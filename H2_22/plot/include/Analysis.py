from pathlib import Path

import ROOT
from ROOT import *



class Ana():

    def draw(self, a1, a2="", a3=""):
        return self.tree.Draw(a1, a2, a3)

    def __init__(self, ana_name, in_name = "", folder_run=1) -> None:
        self.anaName = ana_name
        self.runName = in_name
        self.runTag = ""
        self.inFormat = "../data/roottople_new/{}_new.root"
        self.inTreeName = "t"
        self.outFormat = "out/{}/{}/"
        self.plotExten = ".pdf"
        self.use_folder_run = folder_run
        if (in_name != ""): self.configure()
        self.histcnt = 0

    def configure(self):

        self.runNameTag = self.runName + self.runTag
        self.inFilePath = self.inFormat.format(self.runName)
        self.inFile = TFile(self.inFilePath) if (self.runName != "") else nullptr
        self.tree = self.inFile.Get(self.inTreeName) if (self.inFile != nullptr) else nullptr
        self.outPath = self.outFormat.format(self.anaName, "")
        self.outPath = self.outFormat.format(self.runName, self.anaName) if(self.use_folder_run) else self.outPath
        outp = Path(self.outPath)
        outp.mkdir(parents=True, exist_ok=True)

    def close(self):
        pass

    def geth(self, val, range="", cut="", opt="", hname=""):
        self.histcnt += 1
        hnam = "h_temp_" + str(self.histcnt) if (hname=="") else hname
        hpar = "" if (range=="") else "(" + range + ")"
        hval = val + " >> " + hnam + hpar
        self.tree.Draw(hval, cut, opt)
        return gDirectory.Get(hnam)

    def saveas(self, name, extension=""):
        return self.outPath + name + (self.plotExten if (extension=="") else extension) 


