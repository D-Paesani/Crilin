#pragma once
using namespace std; 

#include "recoTime.h"
#define ANA_CLASS_NAME recoTime

void ANA_CLASS_NAME::proc_namer(RPM::BoxCfg *cfg) {
    
  //if(cfg->GetOptions().Contains("name(chan)")) {

  cfg->SetNameCurrent( Form("%s_%d", cfg->GetName().Data(), cfg->GetIndexCurrent()) );
  cfg->SetTitleCurrent( Form("%s [%d]", cfg->GetTitle().Data(), cfg->GetIndexCurrent()) );

}

void ANA_CLASS_NAME::proc_skipUnused(TH1* histObj, RPM::BoxCfg *cfg) { 

  if (cfg->GetOptions().Contains("skip(on)")) {cfg->SetSkipCurrent(1); return;}
  if (histObj->GetEntries() < 1) {cfg->SetSkipCurrent(1); return;}

}

void ANA_CLASS_NAME::proc_times(TH1* histObj, RPM::BoxCfg *cfg) {

  if (histObj->GetEntries() < 1) {cfg->SetSkipCurrent(1); return;}

  double peak, sigma, peakErr, sigmaErr;
  fitTimeGausStandard(histObj, peak, peakErr, sigma, sigmaErr, "none");

}

void ANA_CLASS_NAME::proc_fuzzy(TH1* histObj, RPM::BoxCfg *cfg) { 

  if (histObj->GetEntries() < 1) {cfg->SetSkipCurrent(1); return;}
  AnaVars *vars = (AnaVars*)cfg->GetUserVars();
  TString histName = cfg->GetNameCurrent();

  TCanvas *c_draw = new TCanvas(histName);
  c_draw->cd();
  histObj->SetDrawOption("zcol");
  histObj->Draw("zcol");
  c_draw->SetLogz();
  vars->CONF.outFile->mkdir("templDraw", "", 1)->cd();
  c_draw->Write();

  histName.ReplaceAll("fuzzy", "");  
  TCanvas *spline_can = new TCanvas("spline" + histName); 
  TProfile *teProf = ((TH2*)histObj)->ProfileX(); 
  TSpline5 *teSpline = new TSpline5(teProf);
  TGraphErrors *teSplGr = (TGraphErrors*)(((TH2*)histObj)->ProfileX());

  teProf->SetName("profile" + histName);  
  teSpline->SetName("spline" + histName);
  teSpline->SetLineColor(kOrange);
  teProf->Draw();
  teSpline->Draw("L same");

  teSplGr->SetMarkerStyle(8);
  teSplGr->SetMarkerSize(0.5);
  teSplGr->SetMarkerColor(kBlue);
  teSplGr->SetLineColor(kOrange);

  vars->CONF.outFile->mkdir("profiles", "", 1)->cd();
  spline_can->Write();

  vars->CONF.outFile->mkdir("splineGraph", "", 1)->cd();
  teSplGr->Write("graph" + histName);

  vars->CONF.outFile->mkdir("spline", "", 1)->cd();
  teSpline->Write();
  
}