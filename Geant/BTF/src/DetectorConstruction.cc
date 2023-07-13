#include <sstream>

#include "DetectorConstruction.hh"

#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4NistManager.hh>
#include <G4SystemOfUnits.hh>
#include <G4VisAttributes.hh>
#include <G4Box.hh>
#include <G4Orb.hh>
#include <G4SDManager.hh>

#include <G4GlobalMagFieldMessenger.hh>
#include "G4MultiFunctionalDetector.hh"
#include "G4PSEnergyDeposit.hh"

#include "SD_Dani.hh"
#include "Geometry.hh"

using namespace std;

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  
  auto &geo = Geometry::Instance();

  G4NistManager* nist = G4NistManager::Instance();

  G4Material* CsI = nist->FindOrBuildMaterial("G4_CESIUM_IODIDE");
  G4Material* vacuum = nist->FindOrBuildMaterial("G4_Galactic");
  G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

  G4Element* lead = nist->FindOrBuildElement("Pb", false);
  G4Element* fluorine = nist->FindOrBuildElement("F", false);
  G4Element* chlorine = nist->FindOrBuildElement("Cl", false);
  G4Element* oxygen = nist->FindOrBuildElement("O", false);
  G4Element* silicon = nist->FindOrBuildElement("Si", false);
  G4Element* hydrogen = nist->FindOrBuildElement("H", false);
  G4Element* carbon = nist->FindOrBuildElement("C", false);
  G4Element* copper = nist->FindOrBuildElement("Cu", false);

  G4Material* PbF2 = new G4Material("PbF2", 8.44 * g/cm3, 2);
  PbF2->AddElement(lead, 1);
  PbF2->AddElement(fluorine, 2);

  G4Material* PcbMix = new G4Material("PcbMix", 5.05 * g/cm3, 6);
  PcbMix->AddElement(chlorine, 0.014);
  PcbMix->AddElement(oxygen, 0.083);
  PcbMix->AddElement(silicon, 0.065);
  PcbMix->AddElement(hydrogen, 0.003);
  PcbMix->AddElement(carbon, 0.014);
  PcbMix->AddElement(copper, 0.818);

  G4VSolid* worldBox = new G4Box("world", geo.worldSizeX / 2, geo.worldSizeY / 2, geo.worldSizeZ / 2);
  G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox, vacuum, "world");
  G4VisAttributes* invisVis = new G4VisAttributes();
  invisVis->SetVisibility(false);
  worldLog->SetVisAttributes(invisVis);
  G4VPhysicalVolume* worldPhys = new G4PVPlacement(nullptr, {}, worldLog, "world", nullptr, false, 0);

  G4VSolid* crySolid = new G4Box("cry", geo.cryL / 2, geo.cryW / 2, geo.cryW / 2);
  G4LogicalVolume* cryLog = new G4LogicalVolume(crySolid, PbF2, "cry");
  G4VisAttributes* cryVis = new G4VisAttributes(G4Colour(0, 1, 1, 0.4));
  cryVis->SetVisibility(true);
  cryVis->SetForceSolid(true);
  cryLog->SetVisAttributes(cryVis);

  G4VSolid* readoutSolid = new G4Box("readout", geo.readoutL / 2, geo.cryW * geo.matSize / 2,  geo.cryW * geo.matSize / 2);
  G4LogicalVolume* readoutLog = new G4LogicalVolume(readoutSolid, PcbMix, "readout");
  G4VisAttributes* readoutVis = new G4VisAttributes(G4Colour(1, 0, 1, 0.4));
  readoutVis->SetVisibility(true);
  readoutVis->SetForceSolid(true);
  readoutLog->SetVisAttributes(readoutVis);

  for (int j = 0; j < geo.matLayers; j++) {

    double zCry = 0.5*geo.cryL + geo.caloPosX + geo.matDist*j;
    double zReadout =  geo.caloPosX + geo.matDist*j + geo.cryL + 0.5*geo.readoutL;
 
    new G4PVPlacement(nullptr, G4ThreeVector(zReadout, 0, 0), readoutLog, "readout", worldLog, 0, j);
  
    for (int i = 0; i < geo.matSize; i++) {

      double x = 0.5 * (geo.matSize - 1) - i;
      x *= geo.cryW;

      for (int ii = 0; ii < geo.matSize; ii++) {

        double xx = 0.5 * (geo.matSize - 1) - ii;
        xx *= geo.cryW;

        int cryN = j*geo.matSize*geo.matSize + i*geo.matSize + ii;
        ostringstream name; 
        name<<"cry_"<<j<<"_"<<i<<"_"<<ii;

        new G4PVPlacement(nullptr, G4ThreeVector(zCry, x, xx), cryLog, name.str(), worldLog, 0, cryN);

        geo.cryLay[cryN] = j;
        geo.cryRow[cryN] = i;
        geo.cryCol[cryN] = ii;

        G4cout<<name.str()<<" -> "<<cryN<<G4endl;

      }
    }
  }

  G4cout << *(G4Material::GetMaterialTable()) << G4endl;

  return worldPhys;
}

void DetectorConstruction::ConstructSDandField()
{
  
  G4SDManager* sdManager = G4SDManager::GetSDMpointer();
  sdManager->SetVerboseLevel(2);  

  auto *cryDet = new SD_Dani("cry");
  SetSensitiveDetector("cry", cryDet, true);
  sdManager->AddNewDetector(cryDet);  
  
}
