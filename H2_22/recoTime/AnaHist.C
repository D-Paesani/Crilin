#pragma once
using namespace std; 

#include "recoTime.h"
#define ANA_CLASS_NAME recoTime


void ANA_CLASS_NAME::BookHistograms() {

    cout<<"Creating HistBoxes:"<<endl;  

    PM.SetOutFile(VAR.CONF.outFile);
    PM.SetUserVariables(&VAR);

    PM.SetUserDefNamer(&(ANA_CLASS_NAME::proc_namer));
    PM.SetUserDefProcess(&(ANA_CLASS_NAME::proc_skipUnused)); 

    PM.SetGroup(0);

    PM.SetUseFolders(1);

    int chNo = PAR.outChans;

    PM.AddHistBox("th1f", chNo, "chargeRaw", "", "charge", "pC", 500, 0, 1000, "tag(chan)", nullptr, nullptr);
    PM.AddHistBox("th1f", chNo, "bLineRms", "", "brms", "mV", 100, 0.0, 5,  "tag(chan)", nullptr, nullptr);
    PM.AddHistBox("th1f", chNo, "bLine", "", "bline", "mV", 1000, -200, 200,  "tag(chan)", nullptr, nullptr);

    PM.AddHistBox("th1f", chNo, "timesPs", "", "time", "ns", 500, 0, 100,  "tag(chan)", &(ANA_CLASS_NAME::proc_times), nullptr);
    PM.AddHistBox("th2f", chNo, "slewingPs", "", "charge", "pC", "time", "ns", 100, 0, 1000, 500, 0, 100, "tag(chan)", nullptr, nullptr);
    PM.AddHistBox("th1f", chNo, "flatnessPs", "", "(reco%digi)/reco", "ns", 48, -0.1, 1.1, "tag(chan)", nullptr, nullptr);
    PM.AddHistBox("th1f", chNo, "flatnessPsCdf", "", "", "ns", 300, -0.1, 1.1, "tag(chan)", nullptr, nullptr);

    PM.AddHistBox("th2f", chNo, "fuzzySipm", "", "time", "ns", "norm wf", "", PAR.parSipm.fuzzyBins, PAR.parSipm.fuzzyFrom, PAR.parSipm.fuzzyTo, 600, -0.1, 1.1, "", &(ANA_CLASS_NAME::proc_fuzzy), 0);

    // PM.AddHistBox("th1f", 1, "mcpDiff", "", "", "ns", 100, -2, 2, "tag(off)", &(ANA_CLASS_NAME::proc_times), nullptr);
    // PM.AddHistBox("th1f", 1, "mcpDiff", "", "", "ns", 100, -2, 2, "tag(off)", &(ANA_CLASS_NAME::proc_times), nullptr);
    // PM.AddHistBox("th1f", 1, "sipmDiff", "", "", "ns", 100, -2, 2, "tag(off)", &(ANA_CLASS_NAME::proc_times), nullptr);
    
    cout<<endl<<endl;

}

