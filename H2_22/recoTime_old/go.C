
using namespace std;

#include <iostream> 

#include "TChain.h"
#include "TString.h" 
#include "TSystem.h" 

#include "recoTime.h"
#include "recoTime.C"
#include "AnaLoop.C"
#include "AnaHist.C"
#include "AnaProc.C"

//config 
    #define _runName "run530170"
    #define _runTag ""
    #define _maxEvents -50000

    #define _inFile "../data/roottople/%s.root"
    #define _outFile "../data/recoTime/%s_an%s.root"
    #define _newFile "../data/roottople_new/%s_new%s.root"
    #define _inTree "t"
//config

void go() {

    recoTime *thisAna = new recoTime();
    recoTime::AnaVars *thisVars = &(thisAna->VAR);
    recoTime::AnaConf *thisConf = &(thisVars->CONF);

    thisConf->evLimit = _maxEvents;
    thisConf->runName = _runName;
    thisConf->inFileName = Form(_inFile, _runName);
    thisConf->inTreeName = _inTree;
    thisConf->outFileName = Form(_outFile, _runName, _runTag);
    thisConf->newFileName = Form(_newFile, _runName, _runTag);

    thisConf->set_newTree = 1;
    thisConf->set_genTemplate = 1;
    thisConf->set_doCfScan = 0;
    thisConf->set_doDsScan = 0;
    thisConf->set_saveWaveNorm = 1;

    thisAna->Init();
    
    gErrorIgnoreLevel = kFatal;

    thisAna->Launch();

}







