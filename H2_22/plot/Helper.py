#helper for H2 2022 TB plot scripts
#v1.1

from IPython import get_ipython

import numpy as np
from numpy import random, dtype
from array import array

import math
from math import floor

import matplotlib
import matplotlib.pyplot as plt

from os import path, mkdir
from tqdm import tqdm
from pathlib import Path
import sys



import ROOT
from ROOT import TCanvas, TFile, TPaveText, TMath, TRandom
from ROOT import TF1, TH1, TH1F, TH2D, TH2F, TH3F, TPolyMarker3D, TGraphErrors, TBox, TLine, TAxis, TGaxis
from ROOT import TSpline5, TSpline3
from ROOT import gROOT, gBenchmark, gRandom, gInterpreter, gPad, gStyle, gDirectory
from ROOT import nullptr, kBlue, kRed, kGreen, kBlack, kMagenta, kOrange

ROOT.gROOT.LoadMacro('includes/rootlogon.C')



def FillGraph(gra: TGraphErrors, x, y, ex, ey):
    gra.AddPoint(x, y)
    n = gra.GetN()
    gra.SetPointError(n-1, ex, ey)
    return n



def GetH(tree, val, range="", cut="", opt="", hname="h_temp"):
    hpar = "" if (range=="") else "(" + range + ")"
    hval = val + " >> " + hname + hpar
    tree.Draw(hval, cut, opt)
    return gDirectory.Get("hname")




def FormatH(obj, title, x_label, y_label, stats=1):
    obj.SetStats(stats)
    obj.SetTitle(title)
    obj.GetXaxis().SetTitle(x_label)
    obj.GetYaxis().SetTitle(y_label)




class Canva():

    szdef = [600,400]

    def __init__(self) -> None:
        self.cnt = 0
        self.canvases = []

    def new(self, s1 = szdef[0], s2 =szdef[1]):
        n = "c_" + str(self.cnt)
        self.canvases.append(TCanvas(n, n, s1, s2))
        self.canvases[self.cnt].Draw()
        self.cnt += 1
        return self.canvases[self.cnt-1]

    def savelast(self, titl):
        self.canvases[self.cnt-1].SaveAs(titl)
    



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




class Par():

    cutAnd = " && "
    q0, q1 = "charge[0]", "charge[1]"
    t0, t1 = "tim[0]", "tim[1]"
    mtMcp = "( 0.5*(tim[2]+tim[3]) )"
    dtMcp = "( tim[3]-tim[2] )"
    mtSipm = "( 0.5*(tim[1]+tim[0]) )"
    dtSipm = "( tim[1]-tim[0] )"
    mcSipm = "( 0.5*(charge[1]+charge[0]) )"
    asymSipm = "( (charge[1]-charge[0])/(charge[1]+charge[0]) )"
    xCry = "cryPos[0]"
    yCry = "cryPos[1]"

    def cutRange(self, v1, c1, c2):
            return F"( {v1}>{c1} && {v1}<{c2} )"
        
    def cutRange2(self, v1, v2, c1, c2):
            return F"( {v1}>{c1} && {v1}<{c2} && {v2}>{c1} && {v2}<{c2} )"

    def __init__(self, run) -> None:

        self.fidlarge = np.zeros(4) 
        self.mcpFLP = np.zeros(4)

        if (run == ""):
            self.fidlarge = [1,2,0,100]
            self.mcpFLP = [0,0,3]
            pass
        elif (run == "run530164"):
            self.fidlarge = [5.7, 6.7, 4.7, 5.6]
        elif (run == "run530167"):
            self.fidlarge = [5.9, 7.0, 4.7, 5.6]
        elif (run == "run530181"):
            self.fidlarge = [5.9, 7.0, 4.5, 5.5]
        elif (run == "run530178"):
            self.fidlarge = [5.9, 7.0, 4.5, 5.5]   

        self.fidmidx = 0.5*(self.fidlarge[0]+self.fidlarge[1])
        self.fidmidy = 0.5*(self.fidlarge[2]+self.fidlarge[3])
        self.fidhalfdx = 0.5*(self.fidlarge[1]-self.fidlarge[0])
        self.fidhalfdy = 0.5*(self.fidlarge[3]-self.fidlarge[2])

        self.fidLarge = F"({self.xCry}>{self.fidlarge[0]} && {self.xCry}<{self.fidlarge[1]} && {self.yCry}>{self.fidlarge[2]} && {self.yCry}<{self.fidlarge[3]})" 
        self.fidMiddle = F"({self.xCry}>{self.fidmidx-0.5*self.fidhalfdx} && {self.xCry}<{self.fidmidx+0.5*self.fidhalfdx} && {self.yCry}>{self.fidmidy-0.5*self.fidhalfdy} && {self.yCry}<{self.fidmidy+0.5*self.fidhalfdy})"

        self.fidUL = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidmidx} && cryPos[1]>{self.fidmidy} && cryPos[1]<{self.fidlarge[3]})" 
        self.fidUR = F"(cryPos[0]>{self.fidmidx} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidmidy} && cryPos[1]<{self.fidlarge[3]})" 
        self.fidDL = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidmidx} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidmidy})" 
        self.fidDR = F"(cryPos[0]>{self.fidmidx} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidmidy})" 
        self.fidU = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidmidy} && cryPos[1]<{self.fidlarge[3]})" 
        self.fidD = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidmidy})" 
        self.fidL = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidmidx} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidlarge[3]})" 
        self.fidR = F"(cryPos[0]>{self.fidmidx} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidlarge[3]})" 

        self.fidQuadrants = [self.fidUL, self.fidUR, self.fidDL, self.fidDR]
        self.fidSides = [self.fidU, self.fidD, self.fidL, self.fidR]

        self.flrx = F"{self.fidlarge[0]},{self.fidlarge[1]}"
        self.flry = F"{self.fidlarge[2]},{self.fidlarge[3]}"
