#include "TChain.h"
#include "TString.h" 
#include <iostream> 
using namespace std;



void go(TString arg1) {

    TString runName = arg1;
    TString inName = Form("../data/in/%s.root", runName.Data());
    TString outName = Form("../data/out/%s_an.root", runName.Data());

    TChain chain("tree");  
    chain.Add(inName); 
    chain.Process("analysis.C", runName + " " + inName + " " + outName + " opt3 opt4");

}

