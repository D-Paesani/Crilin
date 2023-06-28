//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Oct  2 15:57:21 2022 by ROOT version 6.24/06
// from TTree t/Klever tree from ascii file 2022
// found on file: /Users/dp/Documents/Programmi/ROOT/H2/data/roottople/run530118.root
//////////////////////////////////////////////////////////

#ifndef daq_h
#define daq_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class daq {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         xRaw[4];
   UShort_t        nStripHit[4];
   UShort_t        nHit[4];
   UShort_t        digiBase[16];
   UShort_t        digiPh[16];
   UShort_t        digiTime[16];
   Float_t         gonio[5];
   Int_t           spill;
   Int_t           step;
   Int_t           eventNumber;
   UShort_t        wave0[1024];
   UShort_t        wave1[1024];
   UShort_t        wave2[1024];
   UShort_t        wave3[1024];
   UShort_t        wave4[1024];
   UShort_t        wave5[1024];
   UShort_t        wave6[1024];
   UShort_t        wave7[1024];

   // List of branches
   TBranch        *b_xRaw;   //!
   TBranch        *b_nStripHit;   //!
   TBranch        *b_nHit;   //!
   TBranch        *b_digiBase;   //!
   TBranch        *b_digiPh;   //!
   TBranch        *b_digiTime;   //!
   TBranch        *b_gonio;   //!
   TBranch        *b_spill;   //!
   TBranch        *b_step;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_wave0;   //!
   TBranch        *b_wave1;   //!
   TBranch        *b_wave2;   //!
   TBranch        *b_wave3;   //!
   TBranch        *b_wave4;   //!
   TBranch        *b_wave5;   //!
   TBranch        *b_wave6;   //!
   TBranch        *b_wave7;   //!

   daq(TTree *tree=0);
   virtual ~daq();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef daq_cxx
daq::daq(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/Users/dp/Documents/Programmi/ROOT/H2/data/roottople/run530118.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/Users/dp/Documents/Programmi/ROOT/H2/data/roottople/run530118.root");
      }
      f->GetObject("t",tree);

   }
   Init(tree);
}

daq::~daq()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t daq::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t daq::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void daq::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("xRaw", xRaw, &b_xRaw);
   fChain->SetBranchAddress("nStripHit", nStripHit, &b_nStripHit);
   fChain->SetBranchAddress("nHit", nHit, &b_nHit);
   fChain->SetBranchAddress("digiBase", digiBase, &b_digiBase);
   fChain->SetBranchAddress("digiPh", digiPh, &b_digiPh);
   fChain->SetBranchAddress("digiTime", digiTime, &b_digiTime);
   fChain->SetBranchAddress("gonio", gonio, &b_gonio);
   fChain->SetBranchAddress("spill", &spill, &b_spill);
   fChain->SetBranchAddress("step", &step, &b_step);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("wave0", wave0, &b_wave0);
   fChain->SetBranchAddress("wave1", wave1, &b_wave1);
   fChain->SetBranchAddress("wave2", wave2, &b_wave2);
   fChain->SetBranchAddress("wave3", wave3, &b_wave3);
   fChain->SetBranchAddress("wave4", wave4, &b_wave4);
   fChain->SetBranchAddress("wave5", wave5, &b_wave5);
   fChain->SetBranchAddress("wave6", wave6, &b_wave6);
   fChain->SetBranchAddress("wave7", wave7, &b_wave7);
   Notify();
}

Bool_t daq::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void daq::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t daq::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef daq_cxx
