#include "RunAction.hh"
#include <G4Gamma.hh>
#include <G4Electron.hh>
#include <G4AccumulableManager.hh>
#include <G4SystemOfUnits.hh>

#include "Analysis.hh"

#include "Geometry.hh"
#include "CONFIGURATION.hh"

RunAction::RunAction(): G4UserRunAction()
{
  
  auto &geo = Geometry::Instance();
  CONFIGURATION conf;

  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetFirstNtupleId(1);
  analysisManager->SetFirstHistoId(1);
  analysisManager->SetFirstNtupleColumnId(0);
  analysisManager->SetNtupleMerging(1);

  analysisManager->CreateNtuple("out", "out"); 
  analysisManager->CreateNtupleDColumn(1, "ene");
  analysisManager->CreateNtupleDColumn(1, "rfu");
  analysisManager->CreateNtupleIColumn(1, "cry"); 
  analysisManager->CreateNtupleIColumn(1, "row"); 
  analysisManager->CreateNtupleIColumn(1, "col"); 
  analysisManager->CreateNtupleIColumn(1, "lay");

  // analysisManager->OpenFile("out.root"); 
  analysisManager->OpenFile("...mettere/percorso/diout..."); 
  
}


void RunAction::BeginOfRunAction(const G4Run*)
{

}

void RunAction::EndOfRunAction(const G4Run* run)
{

  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;

  if (IsMaster()) {

    G4cout << " ------>> fine run globale" << G4endl;
    G4cout << " ------>> # tot eventi generati: " << nofEvents << G4endl;

  }

}

RunAction::~RunAction()
{

G4AnalysisManager::Instance()->Write();
  
}

void RunAction::AddSecondary(const G4ParticleDefinition* particle, G4double energy)
{
 
}
