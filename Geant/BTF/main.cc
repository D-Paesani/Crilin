#include <vector>

#include <G4RunManagerFactory.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>
#include <G4String.hh>
#include <G4UImanager.hh>

#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "G4ScoringManager.hh"
#include "Analysis.hh"
// #include <QGSP.hh>

#include "CONFIGURATION.hh"

using namespace std;

int main(int argc, char** argv)
{

  CONFIGURATION conf;

  vector<G4String> macros;

  auto* runManager = G4RunManagerFactory::CreateRunManager( conf.set_MT > 0 ? G4RunManagerType::MT : G4RunManagerType::Serial );
  runManager->SetNumberOfThreads(conf.set_MT); 
  runManager->SetVerboseLevel(1);

  G4VisManager* visManager = new G4VisExecutive();
  visManager->Initialize();

  runManager->SetUserInitialization(new PhysicsList());
  runManager->SetUserInitialization(new DetectorConstruction());
  runManager->SetUserInitialization(new ActionInitialization());

  G4UIExecutive* ui = nullptr;
  
  G4cout << "--> Eseguo ui ...";
  ui = new G4UIExecutive(argc, argv);
  
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  G4ScoringManager::GetScoringManager();

  if (ui->IsGUI()) {
    UImanager->ApplyCommand("/control/execute macros/ui.mac");
  } else {
    UImanager->ApplyCommand("/run/initialize");
  }

  ui->SessionStart();
  delete ui;

  delete runManager;
  
  G4AnalysisManager::Instance()->CloseFile();

  G4cout<<"\n\n\n---> fine simulazione <---\n\n\n"<<G4endl;

  return 0;
}
