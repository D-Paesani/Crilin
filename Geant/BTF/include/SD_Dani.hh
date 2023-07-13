#ifndef SD_Dani_HH
#define SD_Dani_HH

#include <G4VSensitiveDetector.hh>

#include "HIT_Dani.hh"

class SD_Dani : public G4VSensitiveDetector
{
public:
    SD_Dani(G4String name);

    void Initialize(G4HCofThisEvent*) override;

protected:
    G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist) override;

private:

    HIT_DaniCollection* fHitsCollection { nullptr };
    G4int fHitsCollectionId { -1 };

};

#endif
