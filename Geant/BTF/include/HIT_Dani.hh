#ifndef HIT_Dani_HH
#define HIT_Dani_HH

#include <G4VHit.hh>
#include <G4THitsMap.hh>
#include <G4ThreeVector.hh>

class HIT_Dani : public G4VHit
{

public:
    inline void* operator new(size_t);
    inline void  operator delete(void*);
    
    void SetDeltaEnergy(G4double deltaE) { fDeltaEnergy = deltaE; }
    void SetTime(G4double time) { fTime = time; }
    void SetPosition(G4ThreeVector pos) { fPosition = pos; }
    void SetCryId(G4int c) { fCry = c; }

    G4double GetDeltaEnergy() const { return fDeltaEnergy; }
    G4double GetTime() const { return fTime; }
    G4ThreeVector GetPosition() const { return fPosition; }
    G4int GetCryId() const { return fCry; }
    
private:

    G4double fDeltaEnergy;
    G4double fTime;
    G4ThreeVector fPosition;
    G4int fCry = -1;

};

using HIT_DaniCollection = G4THitsCollection<HIT_Dani>;

extern G4ThreadLocal G4Allocator<HIT_Dani> *hitAllocator;

inline void* HIT_Dani::operator new(size_t)
{
  if (!hitAllocator)
  {
      hitAllocator = new G4Allocator<HIT_Dani>;
  }
  return hitAllocator->MallocSingle();
}

inline void HIT_Dani::operator delete(void *aHit)
{
    if (!hitAllocator)
    {
        hitAllocator = new G4Allocator<HIT_Dani>;
    }
    hitAllocator->FreeSingle((HIT_Dani*) aHit);
}

#endif
