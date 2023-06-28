#pragma once
using namespace std;

#define ANA_CLASS_NAME recoTime
#define TREE_CLASS_NAME daq

#include "includes/ana/anaClass.h"
#include "includes/RootIncludes.h"
#include "includes/Branch2Histo.h"
#include "includes/TGraphHelper.h"
#include "AnaPars.h"
#include "AnaFit.h"

class ANA_CLASS_NAME
{
public:

  TREE_CLASS_NAME *read; 

  static constexpr anaPar PAR;

  struct anavars {

    struct conf {

      TString options, mode, runName, inFileName, outFileName, inTreeName, newFileName;
      TFile *inFile{0}, *outFile{0}, *newFile{0};
      TTree *chain{0}, *newTree{0};
      Long64_t etp{0}, evLimit{-1}, chainEntries{0};
      
      int set_writeOut = 0;
      int set_newTree = 0;
      int set_closeOutFile = 1;
      int set_genTemplate = 0;
      int set_doCfScan = 0;
      int set_doDsScan = 0;
      int set_saveWaveNorm = 0;

    } CONF;


  } VAR;

  typedef struct anavars AnaVars;
  typedef struct anavars::conf AnaConf;

  struct {

    double cryPos[2]{0};
    double wtime[PAR.waveSz]{0};

    double bline[PAR.outChans]{0}, brms[PAR.outChans]{0}, charge[PAR.outChans]{0}, tim[PAR.outChans]{0}, peak[PAR.outChans]{0};
    double timT1[PAR.outChans]{0}, timT2[PAR.outChans]{0}, timPk[PAR.outChans]{0}; 

    double cfScan[2][PAR.cfScanPts]{0};
    double dsScan[2][PAR.dsScanPts]{0};
    float waveNorm[2][(int)((PAR.parSipm.fuzzyTo-PAR.parSipm.fuzzyFrom)/PAR.digiTime)]{0};
    float waveNormTime[2][(int)((PAR.parSipm.fuzzyTo-PAR.parSipm.fuzzyFrom)/PAR.digiTime)]{0};

    void makeNewBranches(TTree *tree) {
      tree->Branch("bline", &bline, Form("bline[%d]/D", PAR.outChans));
      tree->Branch("brms", &brms, Form("brms[%d]/D", PAR.outChans));
      tree->Branch("charge", &charge, Form("charge[%d]/D", PAR.outChans));
      tree->Branch("tim", &tim, Form("tim[%d]/D", PAR.outChans));
      tree->Branch("timT1", &timT1, Form("timT1[%d]/D", PAR.outChans));
      tree->Branch("timT2", &timT2, Form("timT2[%d]/D", PAR.outChans));
      tree->Branch("timPk", &timPk, Form("timPk[%d]/D", PAR.outChans));
      tree->Branch("peak", &peak, Form("peak[%d]/D", PAR.outChans));
      tree->Branch("cryPos", &cryPos, "cryPos[2]/D");
      tree->Branch("wtime", &wtime, Form("wtime[%d]/D", PAR.waveSz));
    }

    void makeNewBranchCfScan(TTree *tree) {
      tree->Branch("cfScan", &cfScan, Form("cfScan[2][%d]/D", PAR.cfScanPts));
    }

    void makeNewBranchDsScan(TTree *tree) {
      tree->Branch("dsScan", &dsScan, Form("dsScan[2][%d]/D", PAR.dsScanPts)); 
    }

    void makeNewBranchWNorm(TTree *tree) {
      tree->Branch("waveNorm", &waveNorm, Form("waveNorm[2][%d]/F", (int)((PAR.parSipm.fuzzyTo-PAR.parSipm.fuzzyFrom)/PAR.digiTime)));
      tree->Branch("waveNormTime", &waveNormTime, Form("waveNormTime[2][%d]/F", (int)((PAR.parSipm.fuzzyTo-PAR.parSipm.fuzzyFrom)/PAR.digiTime)));
    }

  } NEWB;

  ANA_CLASS_NAME() {};
  void Init();
  void Begin();
  virtual void BookHistograms();
  void Terminate();
  void Loop();
  void LoopEntries(Long64_t);  
  void Launch() {
    Begin(); 
    Loop();
    Terminate();
  }

};

#undef ANA_CLASS_NAME
#undef TREE_CLASS_NAME