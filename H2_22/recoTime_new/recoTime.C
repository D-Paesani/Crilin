#pragma once
using namespace std; 

#include "recoTime.h"
#define ANA_CLASS_NAME recoTime
#define TREE_CLASS_NAME daq

void ANA_CLASS_NAME::Begin() { 

   if ( VAR.CONF.set_newTree ) { 
      cout<<endl<<"--> making new file: "<<VAR.CONF.newFileName<<endl<<endl;
      VAR.CONF.newFile = new TFile(VAR.CONF.newFileName, "RECREATE");
      VAR.CONF.newFile ->cd();
      VAR.CONF.newTree = (TTree*)VAR.CONF.chain->CloneTree(0);
      NEWB.makeNewBranches(VAR.CONF.newTree);
      if ( VAR.CONF.set_doCfScan) {NEWB.makeNewBranchCfScan(VAR.CONF.newTree);}
      if ( VAR.CONF.set_doDsScan) {NEWB.makeNewBranchDsScan(VAR.CONF.newTree);}  
      if ( VAR.CONF.set_saveWaveNorm) {NEWB.makeNewBranchWNorm(VAR.CONF.newTree);}  

      for(int i = 0; i < PAR.waveSz; i++) {
         NEWB.wtime[i] = i*PAR.digiTime;
      }
   }

}

void ANA_CLASS_NAME::Terminate() {

   if (VAR.CONF.set_newTree) {
      VAR.CONF.newFile->cd();
      VAR.CONF.newTree->CloneTree()->Write();
      VAR.CONF.newFile->Close();
   } 

   if (VAR.CONF.set_closeOutFile) {
      VAR.CONF.outFile->Close();
      cout<<endl<<endl;
      cout<<endl<<endl<<"----->  output file: "<<endl<<"      root "<<VAR.CONF.outFileName<<endl<<endl;
   }

}

void ANA_CLASS_NAME::Init() {   

   cout<<endl<<"-----> runName: "<<VAR.CONF.runName<<endl;
   cout<<"-----> inFile: "<< VAR.CONF.inFileName<<endl;
   cout<<"-----> outFile: "<<VAR.CONF.outFileName<<endl;

   if (VAR.CONF.chain == 0) {

      if (VAR.CONF.inFile == 0) {
         VAR.CONF.inFile = new TFile(VAR.CONF.inFileName); 
      } 

      VAR.CONF.inFile->GetObject(VAR.CONF.inTreeName, VAR.CONF.chain); 
   }

   read = new TREE_CLASS_NAME(VAR.CONF.chain);

   VAR.CONF.chainEntries = VAR.CONF.chain->GetEntriesFast();
   VAR.CONF.etp = VAR.CONF.evLimit < 0 ? (Long64_t)VAR.CONF.chainEntries : min((Long64_t)VAR.CONF.evLimit, (Long64_t)VAR.CONF.chainEntries); 

   if (VAR.CONF.outFile == nullptr) {
      VAR.CONF.outFile = new TFile(VAR.CONF.outFileName, "RECREATE");
   }

   cout<<"-----> Chain entries: "<<VAR.CONF.chain->GetEntriesFast()<<endl;
   cout<<"-----> Events to process: "<<VAR.CONF.etp<<endl<<endl;

   if (VAR.CONF.set_fitTemplate) {
      cout<<endl<<"--> loading splines file: "<<VAR.CONF.teSpFileName<<endl<<endl;
      cout<<endl<<"--> loading splines: "<<VAR.CONF.teSpName<<endl<<endl;
      VAR.CONF.teSpFile = new TFile(VAR.CONF.teSpFileName); 

      VAR.CONF.teSpline = new teSplineType**[2];

      for (int i = 0; i < 2; i++) {
          
         VAR.CONF.teSpline[i] = new teSplineType*[VAR.CONF.teSplineSliceNo];

         for (int ii = 0; ii < VAR.CONF.teSplineSliceNo; ii++) {

            VAR.CONF.teSpline[i][ii] = (teSplineType*)(VAR.CONF.teSpFile->Get(Form(VAR.CONF.teSpName, i, ii)));

         }
      }

   }
  
}

void ANA_CLASS_NAME::Loop() {  
   
  if (read->fChain == 0) {return;}
  Long64_t nbytes = 0, nb = 0; 

  for (Long64_t jentry=0; jentry<VAR.CONF.etp; jentry++) { 
    Long64_t ientry = read->LoadTree(jentry); 
    if (ientry < 0) {break;}
    nb = read->fChain->GetEntry(jentry); 
    nbytes += nb;
    if (!(jentry%5000)) { cout << Form( "    processing evt %lld / %lld  ( %.0f%% )", jentry, VAR.CONF.etp, (float)(100*jentry/VAR.CONF.etp) ) << endl; }
    LoopEntries(jentry);
  } 
}
