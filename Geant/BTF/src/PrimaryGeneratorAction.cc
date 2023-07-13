#include "PrimaryGeneratorAction.hh"

#include <G4ParticleTable.hh>
#include <G4Event.hh>
#include <G4SystemOfUnits.hh>
#include <G4ParticleGun.hh>
#include <Randomize.hh>
#include <G4RunManager.hh>
#include <G4Run.hh>

using namespace std;

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    
    fgun = new G4ParticleGun();

}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fgun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  
    fgun->GeneratePrimaryVertex(anEvent);

}
