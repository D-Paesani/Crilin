//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb  9 20:44:13 2022 by ROOT version 6.24/06
// from TTree tree/scope data
// found on file: f100kHz_1V.root
//////////////////////////////////////////////////////////

#ifndef analysis_h
#define analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class analysis : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> evt = {fReader, "evt"};
   TTreeReaderValue<Int_t> size = {fReader, "size"};
   TTreeReaderArray<Float_t> time1 = {fReader, "time1"};
   TTreeReaderArray<Float_t> amp1 = {fReader, "amp1"};
   TTreeReaderValue<Float_t> charge1 = {fReader, "charge1"};
   TTreeReaderValue<Float_t> ampPeak1 = {fReader, "ampPeak1"};
   TTreeReaderValue<Float_t> timePeak1 = {fReader, "timePeak1"};
   TTreeReaderValue<Float_t> ampPed1 = {fReader, "ampPed1"};
   TTreeReaderArray<Float_t> time2 = {fReader, "time2"};
   TTreeReaderArray<Float_t> amp2 = {fReader, "amp2"};
   TTreeReaderValue<Float_t> charge2 = {fReader, "charge2"};
   TTreeReaderValue<Float_t> ampPeak2 = {fReader, "ampPeak2"};
   TTreeReaderValue<Float_t> timePeak2 = {fReader, "timePeak2"};
   TTreeReaderValue<Float_t> ampPed2 = {fReader, "ampPed2"};
   TTreeReaderArray<Float_t> time3 = {fReader, "time3"};
   TTreeReaderArray<Float_t> amp3 = {fReader, "amp3"};
   TTreeReaderValue<Float_t> charge3 = {fReader, "charge3"};
   TTreeReaderValue<Float_t> ampPeak3 = {fReader, "ampPeak3"};
   TTreeReaderValue<Float_t> timePeak3 = {fReader, "timePeak3"};
   TTreeReaderValue<Float_t> ampPed3 = {fReader, "ampPed3"};
   TTreeReaderArray<Float_t> time4 = {fReader, "time4"};
   TTreeReaderArray<Float_t> amp4 = {fReader, "amp4"};
   TTreeReaderValue<Float_t> charge4 = {fReader, "charge4"};
   TTreeReaderValue<Float_t> ampPeak4 = {fReader, "ampPeak4"};
   TTreeReaderValue<Float_t> timePeak4 = {fReader, "timePeak4"};
   TTreeReaderValue<Float_t> ampPed4 = {fReader, "ampPed4"};


   analysis(TTree * /*tree*/ =0) { }
   virtual ~analysis() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(analysis,0);

};

#endif

#ifdef analysis_cxx
void analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef analysis_cxx
