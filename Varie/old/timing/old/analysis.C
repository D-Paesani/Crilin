#define analysis_cxx

#include <fstream>
#include <chrono>
#include <TLine.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>

#include "TApplication.h"
#include "TSpectrum.h"
#include "TGraphErrors.h"
#include "TGraphSmooth.h"
#include "TSpline.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TH1F.h"
#include "TF1.h"
#include "TButton.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TMarker.h"
#include "TRandom.h"
#include "TMath.h"
#include "math.h"

#include "HistManager.h"
#include "analysis.h"
#include "logn.h"
#include "pars.h"

using namespace std;

TFile *splineFile;
TSpline5* templSpl;
TDirectory *spline_dir, *splineGr_dir, *samples_dir, *templDraw_dir, *splineDraw_dir, *templResampDraw_dir, *preProcessing_dir;
TFile* outFile;
Long64_t etp, maxEvents, lognGoodFits = 0, teGoodFits = 0;
TString runName;
int doGenTemplate = 0, doFitTemplate = 0;
HistManager HM;

void fuzzyTemp_proc(TH1* histObj, int histN, int& histSkipFlag) { 

   TString histName = histObj->GetName();
   // histName.ReplaceAll("Resamp", "");
   // histName.ReplaceAll("fuzzy", "");

   TCanvas *templDraw_can = new TCanvas(histName);
   templDraw_dir->cd();  
   histObj->SetTitle(histName);
   histObj->SetDrawOption("zcol");
   histObj->Draw("zcol");
   templDraw_can->SetLogz();
   templDraw_can->Write();

   TCanvas *spline_can = new TCanvas(histName + "_spline"); 
   spline_can->cd();

   TProfile *teProf = ((TH2*)histObj)->ProfileX(); 
   TSpline5 *teSpline = new TSpline5(teProf);
   TGraphErrors *teSplGr = (TGraphErrors*)(((TH2*)histObj)->ProfileX());

   teProf->SetName(histName + "_profile");  
   teSpline->SetName(histName + "_spline");
   teSpline->SetLineColor(kOrange);
   teProf->Draw();
   teSpline->Draw("L same");

   splineDraw_dir->cd();  
   spline_can->Write();

   teSplGr->SetMarkerStyle(8);
   teSplGr->SetMarkerSize(.5);
   teSplGr->SetMarkerColor(kBlue);
   teSplGr->SetLineColor(kOrange);

   splineGr_dir->cd();
   teSplGr->Write(histName + "_graph");

   spline_dir->cd();
   teSpline->Write();
}

void times_proc(TH1* histObj, int histN, int& histSkipFlag) { //fitta le distribuzioni tempi con gaus...

   if (TString(histObj->GetName()).Contains("Trig")) {return;} //...tranne quella del trigger 
   gStyle->SetOptFit(1111);
   double tpeak = histObj->GetBinCenter(histObj->GetMaximumBin());
   double tmax = tpeak + 1, tmin = tpeak - 1;
   TF1 timeFit = TF1("g", "gaus", tmin, tmax); timeFit.SetParameter(1, tpeak); timeFit.SetParameter(2, 2);
   histObj->Fit(&timeFit, "R");
   histObj->Fit(&timeFit, "R");
   cout<<Form("----------->> Processed %s" , histObj->GetName())<<endl;
   cout<<runName<<" "<<timeFit.GetParameter(2)<<", "<<timeFit.GetParError(2)<<endl<<endl;
}

void charge_proc(TH1* histObj, int histN, int& histSkipFlag) {

   double min_tmp = histObj->GetXaxis()->GetXmin();
   double max_tmp = histObj->GetXaxis()->GetXmax();
   histObj->GetXaxis()->SetRangeUser(10, 1000);
   double qpeak = histObj->GetBinCenter(histObj->GetMaximumBin());
   histObj->GetXaxis()->SetRangeUser(min_tmp, max_tmp);

   double qmax = qpeak + 80, qmin = qpeak - 80; float pk,sigma;
   TF1 fit1 = TF1("g", "gaus", qmin, qmax); fit1.SetParameter(1, qpeak); fit1.SetParameter(2, 10); histObj->Fit(&fit1, "R"); 
   pk = fit1.GetParameter(1); sigma = fit1.GetParameter(2);
   fit1 = TF1("g", "gaus", pk - 2.5*sigma, pk + 2.5*sigma); fit1.SetParameter(1, pk); fit1.SetParameter(2, sigma); histObj->Fit(&fit1, "R"); 
   pk = fit1.GetParameter(1); sigma = fit1.GetParameter(2);

}

void analysis::Begin(TTree* tree)
{
   cout<<"::::::::::::::::::::: Start analysis :::::::::::::::::::::"<<endl<<endl; 

   TString opti = GetOption();
   cout<<"Options: "<<opti<<endl;
   TObjArray* opt = opti.Tokenize(" ");
   runName                 = ((TObjString*)(opt->At(0)))->String(); cout<<"RunName: "<<runName<<endl;
   TString inName          = ((TObjString*)(opt->At(1)))->String(); cout<<"InFile: "<<inName<<endl;
   TString outName         = ((TObjString*)(opt->At(2)))->String(); cout<<"OutFile: "<<outName<<endl;
   TString modeName        = ((TObjString*)(opt->At(3)))->String(); cout<<"mode: "<<modeName<<endl;
   TString splineFileName  = ((TObjString*)(opt->At(4)))->String(); cout<<"splineFile: "<<splineFileName<<endl;
   TString maxEvtName      = ((TObjString*)(opt->At(5)))->String(); cout<<"maxEvt: "<<maxEvtName<<endl<<endl;

   maxEvents = maxEvtName.Atoll();
   if(modeName == "f") { doGenTemplate = 0; doFitTemplate = 1; }
   else if (modeName == "g") { doGenTemplate = 1; doFitTemplate = 0; }

   outFile = new TFile(outName.Data(), "RECREATE"); 
   outFile->cd();
   Init(tree);

   cout<<"Creating HistBoxes:"<<endl;
   HM.SetOutFile(outFile);
   HM.SetNamerFun(&namerFunc_def);
   
   HM.AddHistBox("th1f", 1, "chargeRaw", "Q", "Q", "pC", qBins, qFrom, qTo, &charge_proc); // da sistemare range di carica in tutto il codice
   HM.AddHistBox("th1f", 1, "bLineRms", "Base line rms", "", "mV", 500, 0.0, 0.2); 
   HM.AddHistBox("th1f", 1, "bLine", "Base line", "", "mV", 500, -0.25, 0.25); 
   HM.AddHistBox("th1f", 1, "timesTrig", "Trigger reco times", "Time", "ns",  tiBins, tiFrom, tiTo, &times_proc);
   HM.AddHistBox("th1f", 1, "timesPseudo", "Template timesPseudo", "Time", "ns",  tiBins, tiFrom, tiTo, &times_proc);  
   HM.AddHistBox("th1f", 1, "timesLogn", "Logn times", "Time", "ns",  tiBins, tiFrom, tiTo, &times_proc); 
   HM.AddHistBox("th1f", 1, "timesTe", "Template times", "Time", "ns",  tiBins, tiFrom, tiTo, &times_proc); 
   HM.AddHistBox("th1f", 1, "timesPk", "Peak times", "Time", "ns",  tiBins, tiFrom, tiTo, &times_proc); 
   HM.AddHistBox("th2f", 1, "pseudoSlewing", "Pseudo time slewing", "Q", "pC", "T", "ns", qBins, qFrom, qTo, tiBins, tiFrom, tiTo); //da sistemare range
   HM.AddHistBox("th2f", 1, "teSlewing", "Template time slewing", "Q", "pC", "T", "ns", qBins, qFrom, qTo, tiBins, tiFrom, tiTo); //da sistemare range
   HM.AddHistBox("th2f", 1, "fuzzy", "Fuzzy template", "Time", "ns", "Normalised Pulse", "", teTiBins, teTiFrom, teTiTo, teAmpBins, -0.1, 1.1, &fuzzyTemp_proc);
   HM.AddHistBox("th2f", 1, "fuzzyResamp", "Fuzzy template resampled", "Time", "ns", "Normalised Pulse", "", teTiBins, teTiFrom, teTiTo, teAmpBins, -0.1, 1.1, &fuzzyTemp_proc);
   HM.AddHistBox("th1f", 1, "timePseudoModBin", "Flatness over bin", "Normalised bin", "",  11, 0, 1.1);
   HM.AddHistBox("th1f", 1, "timeTeModBin", "Flatness over bin", "Normalised bin", "",  11, 0, 1.1);
   HM.AddHistBox("th1f", 1, "teChi2","Chi2", "#chi^{2}/NDOF","", 200, 0, 4);
   HM.AddHistBox("th2f", 1, "teChi2_t", "Chi2 vs time", "T", "ns", "#chi^{2}/NDOF", "", tiBins, tiFrom, tiTo, 100, 0, 5); 
   HM.AddHistBox("th2f", 1, "teChi2_q", "Chi2 vs charge", "Q", "pC",  "#chi^{2}/NDOF", "", qBins, qFrom, qTo, 100, 0, 5); 
   HM.AddHistBox("th1f", 1, "lognChi2","Chi2", "#chi^{2}/NDOF","", 200, 0, 4);
   HM.AddHistBox("th2f", 1, "lognChi2_t", "Logn vs time", "T", "ns", "#chi^{2}/NDOF", "", tiBins, tiFrom, tiTo, 100, 0, 5); 
   HM.AddHistBox("th2f", 1, "lognChi2_q", "Logn vs charge", "Q", "pC",  "#chi^{2}/NDOF", "", qBins, qFrom, qTo, 100, 0, 5); 
   cout<<endl<<endl;

   spline_dir = outFile->mkdir("splines");
   splineGr_dir = outFile->mkdir("splinesGr");
   splineDraw_dir = outFile->mkdir("profiles");
   templDraw_dir = outFile->mkdir("fuzzyTemplDraw");
   samples_dir = outFile->mkdir("randomSpecimens");

   if(doFitTemplate) {
      splineFile = new TFile(splineFileName);
      cout<<"Loading splines from "<<splineFileName<<endl;
      templSpl = (TSpline5*)splineFile->Get("splines/fuzzy_0_spline"); 
      cout<<endl<<endl;
   }

   Long64_t en = fReader.GetEntries();
   etp = min(maxEvents, en);
   cout << "Number of events to process: " << etp << endl << endl;

   gRandom->SetSeed();
   gStyle->SetOptFit(1111);

}

Bool_t analysis::Process(Long64_t entry)
{

   if (entry > etp) {return kFALSE;}
   if (!(entry%100)) {cout << Form( "    processing evt %lld / %lld  ( %.0f%% )", entry, etp, (float)(100*entry/etp) ) << endl;} 
   fReader.SetLocalEntry(entry);

   double toss = gRandom->Uniform(0, etp/50);
   double tiOffs = tiOffsGlobal;
   Int_t waveSz = *size;
   int digiTime_ps = (int)100000/(waveSz - 2);
   double intQ = *charge1*100/(0.4*(waveSz-2)), _pkT = *timePeak1, _pkV = *ampPeak1; // da mettere intQ parametrica in base a waveSz; ma charge1 esce in V*s??
   HM.Fill1d("chargeRaw", 0, intQ);
   double pkV = _pkV, pkT = _pkT;

   if (doCorrectTrigger) { // correzione tempo trigger (non abilitata, sottraiamo alla fine in quadratura)
      TGraph trigGr = TGraph(waveSz);
      for (int k = 0; k < waveSz; k++) {
         trigGr.SetPoint(k, time2[k], amp2[k]);
      }
      TSpline5 trigSp = TSpline5("trigSp", &trigGr); 
      auto trigSpFun = [&trigSp](double *x, double *){ return trigSp.Eval(x[0]); }; 
      TF1 trigFitFun = TF1("trigf", trigSpFun, -0.8, 0.8, 0); //cambiare range here se serve
      double trT = trigFitFun.GetX(0.07); //cambiare thr here se serve
      if ( toss < 1 ) {
         samples_dir->cd();
         TMarker tp = TMarker(trT, trigSp.Eval(trT), 2);
         TCanvas cc = TCanvas(Form("trig_%lld", entry)); cc.cd(); 
         trigGr.SetLineWidth(0); trigGr.SetMarkerStyle(20); trigGr.SetMarkerSize(.2); trigGr.SetMarkerColor(kBlue); trigGr.Draw(""); 
         tp.SetMarkerSize(3); tp.SetMarkerColor(kRed); tp.Draw("same"); 
         trigFitFun.SetLineColor(kRed); trigFitFun.Draw("same");
         trigSp.SetLineColor(kBlack); trigSp.Draw("same");
         cc.Write(); 
      }
      HM.Fill1d("timesTrig", 0, trT);
      tiOffs += trT;
   }
   
   //if(intQ > pippo || intQ < pippa) {return kFALSE;} // mettere qui tagli in carica se servono



   double blTmp = 0, brmsTmp = 0;
   int t1 = (int)1000*tminPseudo/digiTime_ps, t2 = 1000*(int)tmaxPseudo/digiTime_ps, pts = t2 - t1;
   for (int k = t1; k < t2; k++) {
      double v = amp1[k];
      blTmp += v;
      brmsTmp += v*v;
   }  
   blTmp = blTmp/pts;
   brmsTmp = TMath::Sqrt(TMath::Abs(brmsTmp/pts - blTmp*blTmp));
   double ey = TMath::Sqrt(wfEy*wfEy + brmsTmp*brmsTmp);
   HM.Fill1d("bLineRms", 0, brmsTmp);
   HM.Fill1d("bLine", 0, blTmp);

   TGraphErrors waveGr = TGraphErrors(waveSz); // non serve fillare tutta l'onda; in futuro ricordiamoci di stringere range per avere - 10 -> + 80 ns
   for (int k = 0; k < waveSz; k++) {  
      waveGr.SetPoint(k, time1[k], amp1[k]);
      waveGr.SetPointError(k, wfEx, ey); // possiamo anche aggiungere in quadratura a Ey lo RMS della BL -> done :)
   }

   double tmin = tminPseudo, tmax = tmaxPseudo; // andrebbe messo parametrico in funzione di _pkV
   TSpline5 waveSp = TSpline5("wsp", &waveGr); 
   auto waveSpFun = [&waveSp](double *x, double *){ return waveSp.Eval(x[0]); }; 
   TF1 waveFitFun = TF1("fitf", waveSpFun, tmin, tmax, 0); 
   pkV = waveFitFun.GetMaximum(tmin, tmax);
   pkT = waveFitFun.GetMaximumX(tmin, tmax);
   // TF1 gausFit = TF1("g", "gaus", pkT-2, pkT+2.2);  // -1 +1.2
   // gausFit.SetParameter(1, pkT); gausFit.SetParameter(2, 1);
   // waveGr.Fit(&gausFit, "REMQ");
   // pkV = gausFit.GetMaximum();
   double thr = pkV*CF;
   double psT = waveFitFun.GetX(thr); 

   HM.Fill1d("timePseudoModBin", 0, 1000*psT/digiTime_ps - (int)(1000*psT)/digiTime_ps);
   HM.Fill1d("timesPk", 0, pkT - tiOffs - 4);
   HM.Fill1d("timesPseudo", 0, psT - tiOffs);
   HM.Fill2d("pseudoSlewing", 0, intQ, psT - tiOffs);

   if ( toss < 1 ) {
      samples_dir->cd();
      TCanvas cc = TCanvas(Form("tim_%lld", entry)); cc.cd(); 
      gStyle->SetOptFit(1111);
      waveGr.SetLineWidth(0); waveGr.SetMarkerStyle(20); waveGr.SetMarkerSize(.2); waveGr.SetMarkerColor(kBlue); waveGr.Draw(""); 
      waveFitFun.SetLineColor(kTeal); waveFitFun.Draw("same");
      waveSp.SetLineColor(kBlack); waveSp.Draw("same");
      TMarker tp = TMarker(psT, waveSp.Eval(psT), 2); tp.SetMarkerSize(3); tp.SetMarkerColor(kRed); tp.Draw("same"); 
      TLine t1 = TLine(tmin, 0, tmin, pkV); t1.SetLineColor(kRed); t1.Draw("same"); 
      TLine t2 = TLine(tmax, 0, tmax, pkV); t2.SetLineColor(kRed); t2.Draw("same");
      TLine t3 = TLine(tmin, pkV, tmax, pkV); t3.SetLineColor(kPink); t3.Draw("same");
      cc.Write(); 
   }

   double lognT = -9999;
   if (doLogn) { // fitta logn
      TF1 lognFun = TF1("lognFun", logn,  psT - 8, psT + 0.75, 4); //cambiare qui range fit logn
      lognFun.SetParameter(0, -0.5); //controllare
      lognFun.SetParameter(1, 3.0); //controllare
      lognFun.SetParameter(2, pkT); //controllare, forse mettere in funzione di psT
      lognFun.SetParameter(3, pkV*4*1.28); //controllare
      int fitr = waveGr.Fit("lognFun", "REMQ");
      if (fitr<0) {cout<<"----------> logn fit failed: "<<fitr<<endl;}
      else { 
         lognT = lognFun.GetX(CF*pkV); 
         double lognChi2 = lognFun.GetChisquare()/lognFun.GetNDF();
         HM.Fill1d("timesLogn", 0, lognT - tiOffs);
         HM.Fill2d("lognChi2_t", 0, lognT - tiOffs, lognChi2);
         HM.Fill2d("lognChi2_q", 0, intQ, lognChi2);
         HM.Fill1d("lognChi2", 0, lognChi2);
         lognGoodFits++;
      }

      if ( toss < 1 ) {
      samples_dir->cd();
      TCanvas cc = TCanvas(Form("logn_%lld", entry)); cc.cd(); 
      gStyle->SetOptFit(1111);
      waveGr.SetLineWidth(0); waveGr.SetMarkerStyle(20); waveGr.SetMarkerSize(.2); waveGr.SetMarkerColor(kBlue); waveGr.Draw(""); 
      lognFun.SetLineColor(kBlack); lognFun.Draw("same");
      cc.Write(); 
      }
   }

   if ( doGenTemplate && intQ > teQFrom && intQ < teQTo ) { // generazione template
      for(int itime = (int)0.1*waveSz; itime < waveSz; itime++) { //cambiare qui range template
         double wtime =  time1[itime] - psT + tiOffs;
         double wampl = amp1[itime]/pkV; 
         HM.Fill2d("fuzzy", 0, wtime, wampl); 
         HM.Fill2d("fuzzyResamp", 0, wtime, waveSp.Eval(time1[itime])/pkV); // non usato
      } 
   }

   double teT = -9999;
   if (doFitTemplate) { //fitta template
         auto tempSpFun = [&](Double_t *x, Double_t *par){ return par[0]*(templSpl->Eval(x[0]-par[1]))+par[2]; };
         TF1 tempFun("tempFun", tempSpFun, psT - 7.5, psT + 1.8, 3); //da re-ottimizzare range di fit
         tempFun.SetParameter(0, pkV);
         //tempFun.SetParLimits(0, pkV*0.85, pkV*1.15); // controllare e aggiungere limiti su par0
         tempFun.SetParameter(1, psT - tiOffs );
         //tempFun.SetParLimits(1, pkT - 300, pkT - 280);  // controllare e aggiungere limiti su par1
         tempFun.SetParameter(2,  0.);
         tempFun.SetParLimits(2, -0.01, 0.01); //constrollare
         gStyle->SetOptFit(111);
         int fitr = waveGr.Fit( "tempFun", "REMQ" );  //F
         double amp = tempFun.GetParameter(0);      
         if (fitr<0) {cout<<"----------> templ fit failed: "<<fitr<<endl;}
         else { 
            //teT = tempFun.GetParameter(1) + tiOffs; HM.Fill1d("timesTe", 0, teT - tiOffs); //opzione 1
            teT = tempFun.GetX(thr); HM.Fill1d("timesTe", 0, teT - tiOffs); //opzione2, controllare quale è meglio in base ai casi
            double teChi2 = tempFun.GetChisquare()/tempFun.GetNDF(); //cout<<ey<<"   "<<tempFun.GetChisquare()<<"    "<<tempFun.GetNDF()<<endl;
            HM.Fill1d("timeTeModBin", 0, 1000*teT/digiTime_ps - (int)(1000*teT)/digiTime_ps);
            HM.Fill2d("teSlewing", 0, intQ, teT - tiOffs);
            HM.Fill2d("teChi2_t", 0, teT - tiOffs, teChi2);
            HM.Fill2d("teChi2_q", 0, intQ, teChi2);
            HM.Fill1d("teChi2", 0, teChi2);
            teGoodFits++;
         }

         if ( toss < 1 ) {
            samples_dir->cd();
            TCanvas cc = TCanvas(Form("templ_%lld", entry)); cc.cd(); 
            gStyle->SetOptFit(1111);
            waveGr.SetLineWidth(0); waveGr.SetMarkerStyle(20); waveGr.SetMarkerSize(0.4); waveGr.SetMarkerColor(kBlue); waveGr.Draw(); 
            tempFun.SetLineColor(kRed); tempFun.Draw("same"); 
            TMarker tp = TMarker(teT, tempFun.Eval(teT), 2);
            tp.SetMarkerSize(3); tp.SetMarkerColor(kRed); tp.Draw("same"); 
            TLine t1 = TLine(psT, 0, psT, pkV);  t1.SetLineColor(kBlue); t1.Draw("same");
            TLine t2 = TLine(teT, 0, teT, pkV);  t2.SetLineColor(kPink); t2.Draw("same");
            cc.Write(); 
         }
      }

   return kTRUE;
}

void analysis::SlaveBegin(TTree * /*tree*/) {}
void analysis::SlaveTerminate() {}

void analysis::Terminate()
{  
   cout<<endl<<endl;

   HM.ProcessBoxes(); 

   outFile->Close();

   cout<<endl<<endl;
   cout<<"logn efficiency: "<<lognGoodFits<<" / "<<etp<<endl;
   cout<<"logn efficiency: "<<teGoodFits<<" / "<<etp<<endl;

   cout<<endl<<endl<<"::::::::::::::::::::: done :::::::::::::::::::::"<<endl<<endl;

   cout<<endl<<endl<<" ---->>> output file is here:"<<endl<<"      root "<<outFile->GetName()<<endl<<endl;

}