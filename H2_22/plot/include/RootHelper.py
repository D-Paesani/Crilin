import ROOT
from ROOT import TCanvas, TFile, TPaveText, TMath, TRandom
from ROOT import TF1, TH1, TH1F, TH2D, TH2F, TH3F, TPolyMarker3D, TGraphErrors, TBox, TLine, TAxis, TGaxis
from ROOT import TSpline5, TSpline3
from ROOT import gROOT, gBenchmark, gRandom, gInterpreter, gPad, gStyle, gDirectory
from ROOT import nullptr, kBlue, kRed, kGreen, kBlack, kMagenta, kOrange

ROOT.gROOT.LoadMacro('./include/rootlogon.C')



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