#pragma once

struct wavePar {
    int pkStart, pkStop;
    int qStart, qStop, bStart, bStop;
    int tStart, tStop;
    double cf, maxAmp, thr1, thr2;
    int useCf, phCutMin, phCutMax;
    double fuzzyFrom, fuzzyTo;
    int fuzzyBins;
    int invert, genTemplate, fitTemplate, fitLogn;
    double teTdelta, teStart, teStop, teToffs;
};

struct anaPar {

    static constexpr double zT1T2 = 15100; 
    static constexpr double zT1Cry = zT1T2 + 1800;

    static const int outChans = 4;
    
    static const int waveSz = 1024;
    static const int waveReso = 4096;
    static const int waveRange = 1000;
    static constexpr double digiAmp = (float)waveRange/(float)waveReso;
    static constexpr double digiTime = 0.2;

    static constexpr double wfEx = 0*0.2/3.5; 
    static constexpr double wfEy = 0.15;

    static const int cfScanPts = 14;
    static constexpr double cfScanVal[cfScanPts] = {0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.20, 0.22, 0.24, 0.26, 0.28, 0.30};

    static const int dsScanPts = 9;
    static constexpr int dsScanVal[dsScanPts] = {1, 2, 4, 6, 8, 10, 12, 14, 16};

    static constexpr wavePar parSipm = {
        .pkStart = 150,     //pk sarch from [0-1023]
        .pkStop = 400,      //pk search to [0-1023]
        .qStart = -100,     //t - peakTime [ns]
        .qStop = 700,       //t - peakTime [ns]
        .bStart = -200,     //t - peakTime [ns]
        .bStop = -100,      //t - peakTime [ns]
        .tStart = -100,     //t - peakTime [ns]
        .tStop = 10,        //t - peakTime [ns]
        .cf = 0.12,         //const frac
        .thr1 = 10,         //timT1 thr [mV]
        .thr2 = 50,         //timT2 thr [mV]
        .fuzzyFrom = -30,   //template stuff
        .fuzzyTo = 160,     //template stuff
        .fuzzyBins = 1900,  //template stuff
        .phCutMin = 20,     //min ph cut [cnts]
        .phCutMax = 5000,   //max ph cut [cnts]
        .invert = 0,        //polarity
        .genTemplate = 1,   //enable template gen
        .fitTemplate = 1,   //enable template fit
        .teToffs = 0.0,     // offs
        .teStart = -9.0,    // wrt Ps
        .teStop = +3.0,     // wrt Ps
        .fitLogn = 1
    };

    static constexpr wavePar parMcp = {
        .pkStart = 100,
        .pkStop = 250,
        .qStart = -50,
        .qStop = 100,
        .bStart = -100,
        .bStop = -50,
        .tStart = -50,
        .tStop = 2,
        .cf = 0.12,
        .thr1 = 10,
        .thr2 = 50,
        .fuzzyFrom = -30,
        .fuzzyTo = 160,
        .fuzzyBins = 1900,
        .phCutMin = 20,
        .phCutMax = 5000,
        .invert = 1, 
        .genTemplate = 0,
        .fitTemplate = 0,
        .fitLogn = 0
    };

};
