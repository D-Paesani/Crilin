#include "EventAction.hh"

#include <G4SDManager.hh>
#include <G4THitsMap.hh>
#include <G4SystemOfUnits.hh>
#include <G4Event.hh>
#include <G4RunManager.hh>
#include <G4Run.hh>

#include "HIT_Dani.hh"
#include "Analysis.hh"
#include "Geometry.hh"
#include "CONFIGURATION.hh"

using namespace std;

void EventAction::EndOfEventAction(const G4Event* event)
{

  auto &geo = Geometry::Instance();
  CONFIGURATION conf;

  G4AnalysisManager* ana = G4AnalysisManager::Instance();
  if(!event->GetHCofThisEvent()) return;
  if (fCryId < 0) { fCryId = G4SDManager::GetSDMpointer()->GetCollectionID("cry/etc"); }
  HIT_DaniCollection* hitCollection = (HIT_DaniCollection*)(event->GetHCofThisEvent())->GetHC(fCryId);

  G4double eneTot = 0;

  G4double *eneCry;
  if(conf.set_saveCells) { eneCry = new G4double[geo.cryNo]{0}; }

  for (auto hit: *hitCollection->GetVector()) {
    
    if(conf.set_saveCells) { eneCry[hit->GetCryId()] +=  hit->GetDeltaEnergy() / MeV; }

  }

  if(conf.set_saveCells) {
    for(int i = 0; i < geo.cryNo; i++) {

      double ene = eneCry[i];
      if (ene == 0) {continue;}

      ana->FillNtupleDColumn(1, 0, ene); 
      ana->FillNtupleIColumn(1, 2, i);
      ana->FillNtupleIColumn(1, 3, geo.cryRow[i]);
      ana->FillNtupleIColumn(1, 4, geo.cryCol[i]);
      ana->FillNtupleIColumn(1, 5, geo.cryLay[i]);
      ana->AddNtupleRow(1);}
      ana->FillNtupleIColumn(1, 2, -1);
      ana->AddNtupleRow(1);

  }





}

