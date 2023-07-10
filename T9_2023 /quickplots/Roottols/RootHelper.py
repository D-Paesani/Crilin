import ROOT
from ROOT import TCanvas, TFile, TPaveText, TMath, TRandom
from ROOT import TF1, TH1, TH1F, TH2D, TH2F, TH3F, TPolyMarker3D, TGraphErrors, TGraphAsymmErrors, TBox, TLine, TAxis, TGaxis
from ROOT import TSpline5, TSpline3
from ROOT import gROOT, gBenchmark, gRandom, gInterpreter, gPad, gStyle, gDirectory
from ROOT import nullptr, kBlue, kRed, kGreen, kBlack, kMagenta, kOrange
from array import array
import numpy as np

#version: 01 July 2023 
#daniele.paesani@lnf.infn.it
#added: loadstyle option on Canva, added StrHelper, aded GetG
#solved baco in GetH title/name


#########################################################################################
class Canva():

    szdef = [600,400]

    def __init__(self) -> None:
        self.cnt = 0
        self.canvases = []

    def new(self, s1 = szdef[0], s2 =szdef[1], div = None, set_logz = 0):
        n = "c_" + str(self.cnt)
        self.canvases.append(TCanvas(n, n, s1, s2))
        self.canvases[self.cnt].Draw()
        self.cnt += 1
        if div != None:
            self.canvases[self.cnt-1].Divide(div[0],div[1])
        if set_logz == 1:
            self.canvases[self.cnt-1].SetLogz(1)
        return self.canvases[self.cnt-1]

    def savelast(self, titl):
        self.canvases[self.cnt-1].SaveAs(titl)

    def getlast(self, n=0):
        return self.canvases[self.cnt-1-n]

    def cdlast(self, val, n=0):
        return self.getlast(n).cd(val)
    
    def loadstyle(self, macro=""):
        import os.path
        if (macro == ""):
            macro =  os.path.abspath("") + '/Rottols/rootlogon.C'
        elif (macro[0] != "/"):
            macro =  os.path.abspath("") + '/Rottols/' + macro
        print( F"loading macro {macro}")
        ROOT.gROOT.LoadMacro(macro)

    def getnamelast(self): return self.canvases[self.cnt-1].GetName()
#########################################################################################

#########################################################################################
class StrHelper():
    def __init__(self) -> None:
        pass
    def vs(self, vv, vvv):
        return F"({vv}):({vvv})"
    def diff(self, vv, vvv):
        return F"({vv})-({vvv})"
    def sum(self, vv, vvv):
        return F"({vv})+({vvv})"
    def mean(self, vv, vvv):
        return F"0.5*(({vv})+({vvv}))"
    def cAnd(self, v):
        vv = "( "
        for ii in v:
            vv += F"({ii}) && "
        return vv.strip(" && ") + " )"
    def cRng(self, v1, c1, c2): 
        return F"( ({v1}>{c1}) && ({v1}<{c2}) )"   
    def cRngMult(self, vals, c1, c2):
        vv = "( "
        for ii in vals:
            vv += self.cRng(ii, c1, c2) + " && "
        return vv.strip(" && ") + " )"
    def catRng(self, vv, vvv): 
        return vv + "," + vvv
    def asym(self, v1, v2):
        return F"(({v1}-{v2})/({v1}+{v2}))"
#########################################################################################



def FillGraph(gra: TGraphErrors, x, y, ex, ey):
    gra.AddPoint(x, y)
    n = gra.GetN()
    gra.SetPointError(n-1, ex, ey)
    return n

def GetH(tree, val, range="", cut="", opt="", hname="h_temp", htitle=""):
    hpar = "" if (range=="") else "(" + range + ")"
    hval = val + " >> " + hname + hpar
    tree.Draw(hval, cut, opt)
    h = gDirectory.Get(hname)
    if (htitle != ""): h.SetTitle(htitle)
    return h

def GetG(tree, val, rng="", cut="", hname="h_temp", htitle="", mkst=20, mksz=1, mkcol=kBlack, lnsz=1, dodraw=1): #tocheck
    if (dodraw): 
        hpar = "" if (rng=="") else "(" + rng + ")"
        hval = val + " >> " + hname + hpar
        nn = tree.Draw(hval, cut, "goff")
    gra = TGraphErrors(nn, tree.GetV1(), tree.GetV2(), tree.GetV3(), tree.GetV4())
    gra.SetName(hname)
    gra.SetTitle(htitle)
    gra.SetMarkerStyle(mkst)
    gra.SetMarkerSize(mksz) 
    gra.SetMarkerColor(mkcol)
    gra.SetLineColor(mkcol)
    gra.SetLineWidth(lnsz)
    return gra.Clone()

def FormatH(obj, title, x_label, y_label, stats=1):
    obj.SetStats(stats)
    obj.SetTitle(title)
    obj.GetXaxis().SetTitle(x_label)
    obj.GetYaxis().SetTitle(y_label)
