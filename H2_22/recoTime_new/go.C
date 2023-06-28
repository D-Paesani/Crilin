
using namespace std;

#include <iostream> 

#include "TChain.h"
#include "TString.h" 
#include "TSystem.h" 

#include "recoTime.h"
#include "recoTime.C"
#include "AnaLoop.C"

//config 
    #define _runName "run530181"
    #define _runTag ""
    #define _maxEvents -5000

    #define _inFile "../data/roottople/%s.root"
    #define _outFile "../data/recoTime/%s_an%s.root"
    #define _newFile "../data/roottople_new/%s_new%s.root"
    #define _spFile "../data/splines/%s_splines.root"
    #define _spName "spl_c%d_s%d"   
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
    thisConf->teSpFileName = Form(_spFile, _runName);
    thisConf->teSpName = _spName;

    thisConf->set_newTree = 1;
    thisConf->set_genTemplate = 0;
    thisConf->set_fitTemplate = 1;
    thisConf->set_fitLogn = 0;
    thisConf->set_doCfScan = 0;
    thisConf->set_doDsScan = 0;
    thisConf->set_saveWaveNorm = 0;





    thisAna->Init();
    
    gErrorIgnoreLevel = kFatal;

    thisAna->Launch();

}







