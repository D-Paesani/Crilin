#include "SD_Dani.hh"
#include <G4SDManager.hh>
#include <G4SystemOfUnits.hh>

SD_Dani::SD_Dani(G4String name): G4VSensitiveDetector(name)
{
    collectionName.insert("etc");
}

G4bool SD_Dani::ProcessHits(G4Step* aStep, G4TouchableHistory* /*ROhist*/)
{

    if (aStep->GetTotalEnergyDeposit()<=0) {return false;}

    HIT_Dani* hit = new HIT_Dani();
    G4StepPoint *sp = aStep->GetPreStepPoint();

    hit->SetDeltaEnergy(aStep->GetTotalEnergyDeposit());
    hit->SetTime(sp->GetGlobalTime());
    hit->SetPosition(sp->GetPosition());
    hit->SetCryId(sp->GetTouchable()->GetVolume()->GetCopyNo());

    fHitsCollection->insert(hit);

    return true;
}

void SD_Dani::Initialize(G4HCofThisEvent* hcof)
{
    fHitsCollection = new HIT_DaniCollection(SensitiveDetectorName, collectionName[0]);

    if (fHitsCollectionId < 0)
    {
        fHitsCollectionId = G4SDManager::GetSDMpointer()->GetCollectionID(GetName() + "/" + collectionName[0]);
    }

    hcof->AddHitsCollection(fHitsCollectionId, fHitsCollection);
    
}
