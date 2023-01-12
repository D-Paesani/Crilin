#pragma once
using namespace std; 

#include "AnaPars.h"
#include "recoTime.h"
#define ANA_CLASS_NAME recoTime

void ANA_CLASS_NAME::LoopEntries(Long64_t thisEntry) { 

   int clu = 0;
   for (int i = 0; i < 4; i++) { 
      clu += !(read->nHit[i] == 1)
   }
   if (clu != 0) {return;}

   NEWB.cryPos[0] = read->xRaw[0] + (read->xRaw[2] - read->xRaw[0])*(PAR.zT1Cry/PAR.zT1T2);
   NEWB.cryPos[1] = read->xRaw[1] + (read->xRaw[3] - read->xRaw[1])*(PAR.zT1Cry/PAR.zT1T2);

   double toss = gRandom->Uniform(0, VAR.CONF.etp/100);

   double digiTime = PAR.digiTime;
   double digiTimePs = 1000*digiTime;
   double digiAmp = PAR.digiAmp;

   for (int ich = 0; ich < PAR.outChans; ich++) { 

      TGraphErrors waveGra;
      const wavePar *thisPar;
      UShort_t *thisWave;

      double blineSum{0}, blineSum2{0}, blineTmp{0}, pedTmp{0}, brmsTmp{0};
      double chargeTmp{0}, peakTmp{0}, peakTimeTmp{0}, timeTmp{0}, thr{0}, tt1, tt2;
      double valTmp{-99999}, tTmp{0};
      int samMax{0}, baseN{0}, chargeN{0};
      int bFrom, bTo, qFrom, qTo;
      double tmin, tmax;
      TString fuzzyToFill;

      if (ich == 0) {
         thisWave = read->wave3;
         thisPar = &(PAR.parSipm);
         if (read->digiPh[11] < thisPar->phCutMin) {return;} //return
         if (read->digiPh[11] > thisPar->phCutMax) {return;}
         fuzzyToFill = "fuzzySipm";
      } else if (ich == 1) {
         thisWave = read->wave4;
         thisPar = &(PAR.parSipm); 
         if (read->digiPh[12] < thisPar->phCutMin) {return;}
         if (read->digiPh[12] > thisPar->phCutMax) {return;}
         fuzzyToFill = "fuzzySipm";
      } else if (ich == 2) {
         thisWave = read->wave1;
         thisPar = &(PAR.parMcp);
         if (read->digiPh[9] < thisPar->phCutMin) {continue;}
         if (read->digiPh[9] > thisPar->phCutMax) {continue;}
         fuzzyToFill = "";
      } else if (ich == 3) {
         thisWave = read->wave2;
         thisPar = &(PAR.parMcp);
         if (read->digiPh[10] < thisPar->phCutMin) {continue;}
         if (read->digiPh[10] > thisPar->phCutMax) {continue;}
         fuzzyToFill = "";
      } else { 
         continue;
      }

      int sign = thisPar->invert ? -1 : 1;
      int addBase = thisPar->invert ? PAR.waveReso : 0;

      for (int isam = thisPar->pkStart; isam < thisPar->pkStop; isam++) {

         valTmp = sign*thisWave[isam]+addBase;

         if (valTmp > peakTmp) { 
            peakTmp = valTmp; 
            samMax = isam;
            peakTimeTmp = isam * digiTime;
         }

      }

      if(0) { 
         VAR.CONF.outFile->mkdir("wavefull", "", 1)->cd();
         TGraphErrors debgra;
         for (int isam = 0; isam < PAR.waveReso; isam++) {
            fillGraph(&debgra, isam, sign*thisWave[isam]+addBase, 0, 0);
         }
         debgra.SetTitle(Form("%lld", thisEntry));
         debgra.Write(Form("ccc%lld_%d_%d_%f", thisEntry, ich, samMax, peakTmp));
      }

      peakTmp *= digiAmp;

      bFrom = max(0, samMax + thisPar->bStart);
      bTo = min((int)PAR.waveSz, samMax + thisPar->bStop); 
      qFrom = max(0, samMax + thisPar->qStart);
      qTo = min((int)PAR.waveSz, samMax + thisPar->qStop);
      for (int isam = bFrom; isam < qTo; isam++) {

         valTmp = digiAmp * sign*thisWave[isam]+addBase;
         tTmp = isam * digiTime;

         fillGraph(&waveGra, tTmp, valTmp, 0, 0);

         if (isam > bFrom && isam < bTo) {  
            blineSum += valTmp; 
            blineSum2 += valTmp*valTmp; 
            baseN++;
         }

         if (isam > qFrom && isam < qTo) {  
            chargeTmp += valTmp; 
            chargeN++;
         }
      }

      if(0) { 
         VAR.CONF.outFile->mkdir("wavefull_2", "", 1)->cd();
         waveGra.Write(Form("e%lld_%d_%d_%f", thisEntry, ich, samMax, peakTmp));
      }

      blineTmp = blineSum/(double)baseN;
      NEWB.bline[ich] = blineTmp;
      waveGra.MovePoints(0, -blineTmp);   
      brmsTmp = TMath::Sqrt(blineSum2/(double)baseN - blineTmp*blineTmp);
      NEWB.brms[ich] = brmsTmp;
      peakTmp = peakTmp - blineTmp;

      chargeTmp = chargeTmp - (double)chargeN*blineTmp;
      chargeTmp *= digiTime/50;
      NEWB.charge[ich] = chargeTmp;

      tmin = (samMax + thisPar->tStart)*digiTime; 
      tmax = (samMax + thisPar->tStop)*digiTime;
      TSpline5 waveSp = TSpline5("wsp", &waveGra); 
      auto waveSpFun = [&waveSp](double *x, double *){ return waveSp.Eval(x[0]); }; 
      TF1 waveFitFun = TF1("fitf", waveSpFun, tmin, tmax, 0); 
      peakTmp = waveFitFun.GetMaximum(tmin, tmax);
      peakTimeTmp = waveFitFun.GetMaximumX(tmin, tmax);      
      thr = peakTmp * thisPar->cf;
      timeTmp = waveFitFun.GetX(thr);   
      tt1 = waveFitFun.GetX(thisPar->thr1);
      tt2 = waveFitFun.GetX(thisPar->thr2);
      NEWB.peak[ich] = peakTmp;
      NEWB.timPk[ich] = peakTimeTmp;
      NEWB.tim[ich] = timeTmp;
      NEWB.timT1[ich] = tt1;
      NEWB.timT2[ich] = tt2;

      if (VAR.CONF.set_doCfScan && ich < 2) {
         for (int i = 0; i < PAR.cfScanPts; i++){
            NEWB.cfScan[ich][i] = waveFitFun.GetX( peakTmp * PAR.cfScanVal[i] );   
         }
      }

      if ( toss < 1 ) {
         VAR.CONF.outFile->mkdir("specimens", "", 1)->cd();
         TCanvas *cc = new TCanvas(Form("e%lld_ch%d", thisEntry, ich)); cc->cd(); 
         waveGra.SetTitle(Form("bl=%.3f br=%.3f pk=%.2f pt=%.2f rt=%.2f qq=%.2f", blineTmp, brmsTmp, peakTmp, peakTimeTmp, timeTmp, chargeTmp));
         waveGra.SetLineWidth(0); waveGra.SetMarkerStyle(20); waveGra.SetMarkerSize(.2); waveGra.SetMarkerColor(kBlue); waveGra.Draw(""); 
         waveFitFun.SetLineColor(kTeal); waveFitFun.Draw("same");
         waveSp.SetLineColor(kBlack); waveSp.Draw("same");
         TMarker tp = TMarker(timeTmp, waveSp.Eval(timeTmp), 2); tp.SetMarkerSize(3); tp.SetMarkerColor(kRed); tp.Draw("same"); 
         TMarker tp1 = TMarker(tt1, waveSp.Eval(tt1), 2); tp1.SetMarkerSize(3); tp1.SetMarkerColor(kOrange+7); tp1.Draw("same"); 
         TMarker tp2 = TMarker(tt2, waveSp.Eval(tt2), 2); tp1.SetMarkerSize(3); tp2.SetMarkerColor(kOrange+7); tp2.Draw("same"); 
         TLine t0 = TLine(bFrom*digiTime, 0, bFrom*digiTime, peakTmp);  t0.SetLineColor(kPink); t0.Draw("same");
         TLine t1 = TLine(bTo*digiTime, 0, bTo*digiTime, peakTmp);  t1.SetLineColor(kPink); t1.Draw("same");
         TLine t2 = TLine(qFrom*digiTime, 0, qFrom*digiTime, peakTmp); t2.SetLineColor(kBlue); t2.Draw("same");
         TLine t3 = TLine(qTo*digiTime, 0, qTo*digiTime, peakTmp); t3.SetLineColor(kBlue); t3.Draw("same");
         TLine t4 = TLine(0, peakTmp, peakTimeTmp, peakTmp);  t4.SetLineColor(kPink); t4.Draw("same");
         TLine t5 = TLine(tmin, 0, tmin, peakTmp);  t5.SetLineColor(kGreen); t5.Draw("same");
         TLine t6 = TLine(tmax, 0, tmax, peakTmp);  t6.SetLineColor(kGreen); t6.Draw("same");
         cc->Write(); 
         VAR.CONF.outFile->cd();
      }
      
      TGraphErrors *dsGra = VAR.CONF.set_doDsScan ? new TGraphErrors[PAR.dsScanPts] : nullptr;

      int enab = VAR.CONF.set_genTemplate || VAR.CONF.set_doDsScan || VAR.CONF.set_saveWaveNorm;
      if (enab) { //reloop wave enable

         for (int k = 0; k < waveGra.GetN(); k++) {

            double wx = waveGra.GetPointX(k);
            double wy = waveGra.GetPointY(k);
            double wtimenorm = wx - timeTmp;
            double wamplnorm = wy / peakTmp;

            // if (VAR.CONF.set_genTemplate && thisPar->genTemplate) { //gen template
            // }

            if (ich > 1) {continue;} //only SiPM 

            NEWB.waveNorm[ich][k] = wamplnorm; //wave norm
            NEWB.waveNormTime[ich][k] = wtimenorm;

            if (VAR.CONF.set_doDsScan) { //fill ds scan 
               for (int dsidx = 0; dsidx < PAR.dsScanPts; dsidx++) { 
                  if (k % PAR.dsScanVal[dsidx] == 0) { fillGraph(&dsGra[dsidx], wx, wy, 0, 0); }
               }
            }

         }

         if (VAR.CONF.set_doDsScan && ich < 2) { 
            for (int dsidx = 0; dsidx < PAR.dsScanPts; dsidx++) { 
               TSpline5 waveSp = TSpline5("wsp", &dsGra[dsidx]); 
               auto waveSpFun = [&waveSp](double *x, double *){ return waveSp.Eval(x[0]); }; 
               TF1 waveFitFun = TF1("fitf", waveSpFun, tmin, tmax, 0); 
               peakTmp = waveFitFun.GetMaximum(tmin, tmax);
               timeTmp = waveFitFun.GetX(thr);   
               NEWB.dsScan[ich][dsidx] = timeTmp;

               VAR.CONF.outFile->mkdir("downsampled", "", 1)->cd();
               if (toss<0.1) { dsGra[dsidx].Write(Form("ev%lld_ch%d_dsf%d", thisEntry, ich, PAR.dsScanVal[dsidx])); }
            }
         }

      }

   }

   if (VAR.CONF.set_newTree) {VAR.CONF.newTree->Fill();}
    
} 








