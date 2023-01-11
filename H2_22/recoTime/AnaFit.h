#pragma once

int fitTimeGausStandard(TH1 *hist, double& peak, double &peakErr, double &sigma, double &sigmaErr, TString options) {
    
    gStyle->SetOptFit(1111111);
    hist->SetStats(1111111);

    peak = hist->GetBinCenter(hist->GetMaximumBin());
    sigma = hist->GetRMS();
    TF1 gaus = TF1("g", "gaus");
    gaus.SetParameter(1, peak); 
    gaus.SetParameter(2, sigma);
    if ( (hist->Fit(&gaus, "EMQ")) < 0 ) {return -1;}     
    peak = gaus.GetParameter(1); 
    sigma = gaus.GetParameter(2);
    gaus.SetParameter(1, peak); 
    gaus.SetParameter(2, sigma);
    gaus.SetRange(peak - 4*sigma, peak + 4*sigma); 
    if ( (hist->Fit(&gaus, "REMQ")) < 0 ) {return -1;}     
    peak = gaus.GetParameter(1); 
    sigma = gaus.GetParameter(2);
    peakErr = gaus.GetParError(1);
    sigmaErr = gaus.GetParError(2); 
    
    return 1;
}


            
            






