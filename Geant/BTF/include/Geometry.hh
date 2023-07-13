#pragma once

class Geometry
{
private:

    Geometry() {}
    ~Geometry() {}

public:

    static Geometry& Instance() {
        static Geometry s;
        return s;
    } 

    Geometry(const Geometry &) = delete;
    Geometry & operator = (const Geometry &) = delete;

public:

    static constexpr G4double worldSizeX = 2 * m;
    static constexpr G4double worldSizeY = 2.5 * m;
    static constexpr G4double worldSizeZ = 2.5 * m;

    static constexpr G4double cryW = 10 * mm;
    static constexpr G4double cryL = 40 * mm;
    static constexpr G4double matSize = 3;
    static constexpr G4double matLayers = 2;
    static constexpr G4double matDist = cryL + 5 * mm;
    static constexpr G4double readoutL = 5 * mm;

    static constexpr G4double caloPosX = 50 * cm;

    static const G4int cryNo = matSize*matSize*matLayers;
    
    G4int cryRow[cryNo];
    G4int cryCol[cryNo];
    G4int cryLay[cryNo];

};
