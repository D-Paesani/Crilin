#include "TChain.h"
#include "TString.h" 
#include <iostream> 
using namespace std;


#define __runName "s2.5"
#define _splinesName "s40"
#define _analysisMode "f" 
#define _maxEvents "5000"

#define _analysisName "analysis.C" 
#define _analysisInTreeName "tree"

TString _inFormat = "../data/in/%s.root";
TString _outAnaName = "../data/out/%s_an.root";
TString _outTemplName = "../data/splines/splines_%s.root";
TString _splinesFileName = _outTemplName;
TString _outName, _inName, _analysisParams, _runName = __runName;

// TString listSamples[5] = {"s2.5","s5","s10","s20","s40"};
// TString listAmpl[7] = {"a0.15","a0.4","a0.7","a1.0","a1.3","a1.6"};


void go(TString arg1 = __runName) {

    _runName = arg1;

    if (_analysisMode == "g") { _outName = _outTemplName; }
    else if (_analysisMode == "f") {  _outName = _outAnaName; }
    _inName = Form(_inFormat, _runName.Data());

    _analysisParams  = " "; _analysisParams += _runName;
    _analysisParams += " "; _analysisParams += _inName;
    _analysisParams += " "; _analysisParams += Form(_outName, _runName.Data());
    _analysisParams += " "; _analysisParams += _analysisMode;
    _analysisParams += " "; _analysisParams += Form(_splinesFileName, _splinesName);
    _analysisParams += " "; _analysisParams += _maxEvents;

    TChain chain(_analysisInTreeName);  
    chain.Add(_inName);

    chain.Process(_analysisName, _analysisParams);

}







