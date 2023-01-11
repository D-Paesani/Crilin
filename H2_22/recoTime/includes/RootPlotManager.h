//new exciting stuff
//change namer function (?????)
//add varAxis class  --> title, unit, range, bins, style

// static void HistProcessor(TH1* hist, RPM::BoxCfg *cfg) {};
// static void GraphProcessor(TGraphErrors* gra, RPM::BoxCfg *cfg) {};
// static void Namer(RPM::BoxCfg *cfg) {};

// ************************************************************************************************

#define RPM_VERSION 4.1

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <vector>
#include <iostream>
#include <TApplication.h>
#include <TH1.h>
#include <stdlib.h>
#include <TFrame.h>
#include <unordered_map>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TProfile.h>
#include <TObjString.h>
#include <TPaveText.h>
#include <TPaveStats.h>
#include <TF1.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <vector>
#include <TString.h>
#include <TTimer.h>
#include <TLatex.h>
#include <TGClient.h>
#include <TRootCanvas.h>
#include <TDatime.h>
#include <time.h>
#include <TH2Poly.h>

using namespace std;

class RootPlotManager 
{

protected: //BoxConfig

  struct BoxConfig {

    protected:

    void *userVars;
    TDirectory *bDir, *hDir, *outDir;
    TString bName, bTitle, bOptions, bType;
    int bNum{0}, bGroup{0}, bUseFolder{1}, bUseFolderIndividual{0};
    TString hName, hTitle;
    int hNum{-1}, hSkip{0};

    void ResetCurrent() {hName = "", hTitle = "", hNum = -1, hSkip = 0;}

    public:

    int GetGroup() {return bGroup;}         
    int GetSize() {return bNum;}            
    TString GetName() {return bName;}       
    TString GetTitle() {return bTitle;}       
    TString GetOptions() {return bOptions;} 
    void * GetUserVars() {return userVars;}
    
    TString GetNameCurrent() {return hName;}          
    TString GetTitleCurrent() {return hTitle;}          
    int GetIndexCurrent() {return hNum;}              
    int GetSkipCurrent() {return hSkip;}              

    void SetTitleCurrent(TString t) {hTitle = t;}
    void SetNameCurrent(TString t) {hName = t;}
    void SetSkipCurrent(int s) {hSkip = s;}

    TDirectory *GetDirectory(TString type) {
      if (type == "box") {return bDir;}
      if (type == "obj") {return hDir;}
      if (type == "out") {return hDir;}
      return nullptr;
    } 
    
  };

public: //BoxConfig type

  typedef struct BoxConfig BoxCfg;
  
private: //Error and debug
  
  static void RPMErrorHandler(TString err, TString type) {
    cout<<"-----> RootPlotManager: ERROR:"<<err<<endl; 
    exit(EXIT_FAILURE); 
  }

  static void RPMDebugHandler(int deb, TString msg) {
    if (deb <= 0) {return;}
    cout<<"-----> RootPlotManager: "<<msg<<endl; 
  }

private: //Namers and Processors

  typedef void (*_ProcessFunction)(TH1*, BoxCfg*);
  typedef void (*_ProcessGraphFunction)(TGraphErrors*, BoxCfg*);
  typedef void (*_NamerFunction)(BoxCfg*);

  static void processFunc_def(TH1* hObj, BoxCfg *cfg) {};
  static void processGraphFunc_def(TGraphErrors* hObj, BoxCfg *cfg) {};

  static void namerFunc_def(BoxCfg *cfg) { 
    cfg->SetNameCurrent( Form("%s_%d", cfg->GetName().Data(), cfg->GetIndexCurrent()) );
    cfg->SetTitleCurrent( Form("%s [%d]", cfg->GetTitle().Data(), cfg->GetIndexCurrent()) );
  };

  _ProcessFunction proc_def = &processFunc_def;
  _ProcessFunction procUser_def = &processFunc_def; 
  _ProcessGraphFunction procGraphUser_def = &processGraphFunc_def; 
  _ProcessGraphFunction procGraph_def = &processGraphFunc_def;
  _NamerFunction namerUser_def = &namerFunc_def;
  _NamerFunction namer_def = &namerFunc_def;

public: //Namers and Processor types

  typedef void (ProcessFunction) (TH1*, BoxCfg*);
  typedef void (ProcessGraphFunction) (TGraphErrors*, BoxCfg*);
  typedef void (NamerFunction) (BoxCfg*);

private: //HistBox

  class HistBox: private BoxConfig
  {       

  private:

    TString formatLabel = "%s [%s]";
    TString formatEntries = "Entries / %.2f %s";
    TString formatEntriesNoUnit = "Entries";

    TH1 **histosObj;
    BoxCfg cfg;
    TString l1, l2;
    int dbug;

    _ProcessFunction processFunction; 
    _NamerFunction namerFunction;

  public:
    
    HistBox() {}
    ~HistBox() {}

    BoxCfg* GetConf() {return (BoxCfg*)this;}
    
    TH1** GetHistosObj(){ return histosObj; }

    TH1* GetHistObj(int k){ 
      if (k > bNum) {return nullptr;}
      return histosObj[k]; 
    }

    HistBox(
      TDirectory *outdir, int useFolder, int useFolderIndividual, int group, int debug,
      TString type, int num, TString name, TString title, TString label1, TString label2, TString label3, TString label4,
      int xBins, double xMin, double xMax, int yBins, double yMin, double yMax,
      _ProcessFunction process, _NamerFunction namer, void *vars = nullptr, TString options = ""
    ):
      processFunction(process), namerFunction(namer), dbug(debug)
    {

      if (title == "") { title = name; }
      
      outDir = outdir;
      bUseFolder = useFolder;
      bUseFolderIndividual = useFolderIndividual;
      bGroup = group;
      bType = type;
      bNum = num;
      bName = name;
      bTitle = title;
      userVars = vars;
      bOptions = options;

      RPMDebugHandler(dbug, Form("HistBox constructor: [%s] [%d] [%s] [%s]", type.Data(), num, name.Data(), title.Data()) );

      histosObj = new TH1*[num];

      if (type == "th1f") { 

        if (label2 == "") {
          l2 = formatEntriesNoUnit;
          l1 = label1;
        } else {
          l2 = Form(formatEntries, ((xMax-xMin)/(double)xBins), label2.Data());
          l1 = Form(formatLabel, label1.Data(), label2.Data());
        }

        for(int k=0; k<num; k++){
          hNum = k;
          namerFunction(GetConf());
          histosObj[k] = new TH1F(hName, hTitle, xBins, xMin, xMax);
        }

      } else if (type == "th2f") {

        if (label2 == "") { l1 = label1; } 
        else { l1 = Form(formatLabel, label1.Data(), label2.Data()); }
        
        if (label4 == "") { l2 = label3; } 
        else { l2 = Form(formatLabel, label3.Data(), label4.Data()); }

        for(int k=0; k<num; k++){
          hNum = k;
          namerFunction(GetConf());
          histosObj[k] = new TH2F(hName, hTitle, xBins, xMin, xMax, yBins, yMin, yMax); 
        }      
            
      } else if (type == "tprofile" || type == "prof") { 

        l2 = label3;

        if (label2 == "") {
          l2 = formatEntriesNoUnit;
          l1 = label1;
        } else {
          l2 = Form(formatEntries, ((xMax-xMin)/(double)xBins), label2.Data());
          l1 = Form(formatLabel, label1.Data(), label2.Data());
        }

        for(int k=0; k<num; k++){
          hNum = k;
          namerFunction(GetConf());
          histosObj[k] = new TProfile(hName, hTitle, xBins, xMin, xMax);
        }

      } else {
        RPMErrorHandler("HistBox: histType not supported", "");
      }

      ResetCurrent();

    };
  
    void ProcessBox(){

      if (bUseFolder == 1) {
        hDir = bDir = outDir->mkdir(bName.Data(), "recreate"); 
      } else {
        hDir = bDir = outDir;
      }
 
      for (int k = 0; k < bNum; k++) {

        if (bUseFolderIndividual) { 
          hDir = bDir->mkdir(GetHistObj(k)->GetName());
        }

        GetHistObj(k)->GetXaxis()->SetTitle(l1);
        GetHistObj(k)->GetYaxis()->SetTitle(l2);

        hDir->cd();
        hNum = k;
        hSkip = 0;
        hName = GetHistObj(k)->GetName();
        hTitle = GetHistObj(k)->GetTitle();
        processFunction(GetHistObj(k), GetConf());
        if (hSkip) {continue;}  
        hDir->cd();
        GetHistObj(k)->Write();

      } 
      
      ResetCurrent();
    
    };

  };

private: //GraphBox

  class GraphBox: private BoxConfig
  {

  private: 

    TString formatLabel = "%s [%s]";

    TMultiGraph *multiObj = nullptr;
    TGraphErrors **graphsObj = nullptr;
    TString l1, l2;
    int dbug;

    _ProcessGraphFunction processFunction; 
    _NamerFunction namerFunction;

  public:

    GraphBox() {}
    ~GraphBox() {}

    BoxCfg* GetConf() {return (BoxCfg*)this;}
    TGraphErrors** GetGraphsObj(){ return graphsObj; }
    TGraphErrors* GetGraphObj(int k){ return graphsObj[k]; }
    TMultiGraph* GetMultiGraphObj() {return multiObj;}

    GraphBox(
      TDirectory *outdir, int useFolder, int useFolderIndividual, int group, int debug,
      TString type, int num, TString name, TString title, TString label1, TString label2, TString label3, TString label4,
      _ProcessGraphFunction process, _NamerFunction namer, void *vars = nullptr, TString options = "", 
      int useMulti = 0, int markStyle = 1, int markColor = kBlack, int markSize = 1, int lineStyle = 1, int lineColor = kBlack, int lineSize = 1
    ):  
      namerFunction(namer), processFunction(process), dbug(debug)
    { 

      if (title == "") { title = name; }

      outDir = outdir;
      bUseFolder = useFolder;
      bUseFolderIndividual = useFolderIndividual;
      bGroup = group;
      bType = type;
      bNum = num;
      bName = name;
      bTitle = title;
      userVars = vars;
      bOptions = options;

      RPMDebugHandler(dbug, Form("GraphBox constructor: [%s] [%d] [%s] [%s]", type.Data(), num, name.Data(), title.Data()) );

      if (type == "tge") {

        if (useMulti) {multiObj = new TMultiGraph(name, title);}
        graphsObj = new TGraphErrors*[num];

        if (label2 == "") { l1 = label1; } 
        else { label1 = Form(formatLabel, label1.Data(), label2.Data()); }
        if (label4 == "") { l2 = label3; } 
        else { label2 = Form(formatLabel, label3.Data(), label4.Data()); }

        for(int k=0; k<num; k++){
          hNum = k;
          namerFunction(GetConf());        
          
          graphsObj[k] = new TGraphErrors();
          if (useMulti) {multiObj->Add(GetGraphObj(k));}

          GetGraphObj(k)->SetName(hName);
          GetGraphObj(k)->SetTitle(hTitle);
          GetGraphObj(k)->SetMarkerStyle(markStyle);
          GetGraphObj(k)->SetMarkerColor(markColor);
          GetGraphObj(k)->SetLineStyle(lineStyle);
          GetGraphObj(k)->SetLineColor(lineColor);
          GetGraphObj(k)->SetLineWidth(lineSize);
          GetGraphObj(k)->GetXaxis()->SetTitle(l1);
          GetGraphObj(k)->GetYaxis()->SetTitle(l2);

        }    

      } else {
        RPMErrorHandler("GraphBox: graphType not supported", "");
      }

      ResetCurrent();

    };

    void ProcessBox(){

      if (bUseFolder == 1) {
        hDir = bDir = outDir->mkdir(bName, "recreate"); 
      } else {
        hDir = bDir = outDir;
      }
 
      for (int k = 0; k < bNum; k++) {

        if (bUseFolderIndividual) { 
          hDir = bDir->mkdir(GetGraphObj(k)->GetName()); 
        }

        GetGraphObj(k)->GetXaxis()->SetTitle(l1);
        GetGraphObj(k)->GetYaxis()->SetTitle(l2);

        hDir->cd();
        hNum = k;
        hSkip = 0;
        hName = GetGraphObj(k)->GetName();
        hTitle = GetGraphObj(k)->GetTitle();
        processFunction(GetGraphObj(k), GetConf());
        if (hSkip) {continue;}  
        hDir->cd();
        GetGraphObj(k)->Write();

      } 
      
      ResetCurrent();
    
    };

  };

private: //RootPlotManager vars

  void *userVars = nullptr;

  TFile *outFile = nullptr;
  TDirectory *outDir = nullptr;
    
  int useFolders{1}, useFolderIndividual{0}, useGraphMulti{0}, boxGroup{0}, debug{1};

  unordered_map<string, HistBox *> HistBoxes;
  unordered_map<string, GraphBox *> GraphBoxes;

public: //Constructors

  RootPlotManager() {}
  ~RootPlotManager() {}

public: //Namers and Processors

  void SetUserDefNamer(_NamerFunction namerFunc) { namerUser_def = namerFunc; }
  _NamerFunction GetUserDefNamer() { return namerUser_def; }
  _NamerFunction GetDefNamer() { return namer_def; }

  void SetUserDefProcess(_ProcessFunction processFunc) { procUser_def = processFunc; }
  _ProcessFunction GetUserDefProcess() { return procUser_def;}
  _ProcessFunction GetDefProcess() { return proc_def;}

  void SetUserDefGraphProcess(_ProcessGraphFunction processFunc) { procGraphUser_def = processFunc; }
  _ProcessGraphFunction GetUserDefGraphProcess() { return procGraphUser_def;}
  _ProcessGraphFunction GetDefGraphProcess() { return procGraph_def;}

private: //GetBoxes

  HistBox *GetHistBox(string name) {return HistBoxes[name];}
  GraphBox *GetGraphBox(string name) {return GraphBoxes[name];}

public: //Configuration

  void SetGraphUseMulti(int s) { useGraphMulti = s; }
  void SetUseFoldersIndividual(int i) { useFolderIndividual = i; }
  void SetUseFolders(int i) { useFolders = i; }
  void SetOutDir(TDirectory *d) { outDir = d; }
  void SetOutFile(TFile *f) { outFile = f; outDir = f; }
  void SetGroup(int g) { boxGroup = g; }
  void SetUserVariables(void * v) { userVars = v; }
  void SetDebugLevel(int d) {debug = d;}

  TFile *GetOutFile() { return outFile; }
  TDirectory *GetOutDir() { return outDir; }
  void CloseOutFile() { outFile->Close(); }

  BoxCfg *GetHistBoxConf(string n) {return GetHistBox(n)->GetConf();}
  BoxCfg *GetGraphBoxConf(string n) {return GetGraphBox(n)->GetConf();}

public: //HistBoxes methods

  void AddHistBox(TString, int, TString, TString, TString, TString, TString, TString, int, double, double, int, double, double, TString, _ProcessFunction, _NamerFunction);
  void AddHistBox(TString, int, TString, TString, TString, TString, int, double, double, TString, _ProcessFunction, _NamerFunction);

  int RemoveBox(TString name) { return 1; }

  TH1 **GetHistos(string name) { return (TH1**)HistBoxes[name]->GetHistosObj(); }
  TH1 *GetHist(string name, int n) { return (TH1*)HistBoxes[name]->GetHistObj(n); }

  void Fill2d(string name, int n, double val1, double val2, double w = 1) { ((TH2F*)GetHist(name, n))->Fill(val1, val2, w); }
  void Fill1d(string name, int n, double val1, double w = 1) { ((TH1F*)GetHist(name, n))->Fill(val1, w); }
  
  void Fill2dIf(int enable, string name, int n, double val1, double val2, double w = 1) { 
    if (!enable) {return;}
    ((TH2F*)GetHist(name, n))->Fill(val1, val2, w); 
  }

  void Fill1dIf(int enable, string name, int n, double val1, double w = 1) { 
    if (!enable) {return;}
    ((TH1F*)GetHist(name, n))->Fill(val1, w); 
  }

  void ProcessBox(string name) { HistBoxes[name]->ProcessBox(); }

  void ProcessHistBoxes(int group = -999) {
    for (auto& HistBox: HistBoxes) {
      if (HistBox.second->GetConf()->GetGroup() != group && group >= 0) {continue;}
      HistBox.second->ProcessBox(); 
    }      
  };

public: //GraphBoxes methods

  void AddGraphBox(TString, int, TString, TString, TString, TString, TString, TString, TString, _ProcessGraphFunction, _NamerFunction, int, int, int, int, int, int);
  void AddGraphBox(TString, int, TString, TString, TString, TString, TString, TString, TString, _ProcessGraphFunction, _NamerFunction);

  int RemoveGraphBox(TString name) { return 1; }

  TGraphErrors* GetGraph(string name, int n) {return (TGraphErrors*)GraphBoxes[name]->GetGraphObj(n); }

  int FillGraph(string name, int n, double x, double y, double ex, double ey) { 
    TGraphErrors * g = GetGraph(name, n);
    g->AddPoint(x, y);
    int np = g->GetN();
    g->SetPointError(np - 1, ex, ey);
    return np;
  }

  int FillGraphIf(int enable, string name, int n, double x, double y, double ex, double ey) { 
    if (!enable) {return -1;}
    TGraphErrors * g = GetGraph(name, n);
    g->AddPoint(x, y);
    int np = g->GetN();
    g->SetPointError(np - 1, ex, ey);
    return np;
  }
  
  void ProcessGraphBox(string name) { GraphBoxes[name]->ProcessBox(); }

  void ProcessGraphBoxes(int group = -999) {
    for (auto& GraphBox: GraphBoxes) {
      if (GraphBox.second->GetConf()->GetGroup() != group && group >= 0) {continue;}
      GraphBox.second->ProcessBox(); 
    }
  };

public: //Boxes methods  

  void ProcessBoxes(int group = -999) {ProcessHistBoxes(group); ProcessGraphBoxes(group);}

};

void RootPlotManager::AddHistBox( 
  TString type, int num, TString name, TString title, TString label1, TString label2, TString label3, TString label4,
  int xBins, double xMin, double xMax, int yBins, double yMin, double yMax,
  TString options, _ProcessFunction processor, _NamerFunction namer
) {

  if (namer == nullptr) {namer = namerUser_def;}
  if (processor == nullptr) {processor = procUser_def;}

  RootPlotManager::HistBoxes.insert( 
    {
      name.Data(), 
      new HistBox(
        outDir, useFolders, useFolderIndividual, boxGroup, debug,
        type, num, name, title, label1, label2, label3, label4, 
        xBins, xMin, xMax, yBins, yMin, yMax, 
        processor, namer, userVars, options
      )
    } 
  );
  
};

void RootPlotManager::AddHistBox( 
  TString type, int num, TString name, TString title, TString label1, TString label2, 
  int xBins, double xMin, double xMax, 
  TString options, _ProcessFunction processor, _NamerFunction namer
) { RootPlotManager::AddHistBox(type, num, name, title, label1, label2, "", "", xBins, xMin, xMax, 0, 0, 0, options, processor, namer); };


void RootPlotManager::AddGraphBox(
  TString type, int num, TString name, TString title, TString label1, TString label2, TString label3, TString label4, 
  TString options, _ProcessGraphFunction processor, _NamerFunction namer,
  int s1, int s2, int s3, int s4, int s5, int s6
) {

  if (namer == nullptr) {namer = namerUser_def;}
  if (processor == nullptr) {processor = procGraphUser_def;}

  RootPlotManager::GraphBoxes.insert( 
    {
      name.Data(), 
      new GraphBox(
        outDir, useFolders, useFolderIndividual, boxGroup, debug,
        type, num, name, title, label1, label2, label3, label4,        
        processor, namer, userVars, options, useGraphMulti, 
        s1, s2, s3, s4, s5, s6
      )
    } 
  );

}

void RootPlotManager::AddGraphBox( 
  TString type, int num, TString name, TString title, TString label1, TString label2, TString label3, TString label4, 
  TString options, _ProcessGraphFunction processor, _NamerFunction namer
) { RootPlotManager::AddGraphBox(type, num, name, title, label1, label2, label3, label4, options, processor, namer, 1, 1, 1, 1, 1, 1); };

typedef RootPlotManager RPM;