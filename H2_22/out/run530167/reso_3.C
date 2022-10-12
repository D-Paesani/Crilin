void reso_3()
{
//=========Macro generated from canvas: c_2/c_2
//=========  (Wed Oct 12 14:26:37 2022) by ROOT version 6.24/06
   TCanvas *c_2 = new TCanvas("c_2", "c_2",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_2->SetHighLightColor(2);
   c_2->Range(18.86673,-0.001355343,328.7433,0.03219808);
   c_2->SetFillColor(0);
   c_2->SetBorderMode(0);
   c_2->SetBorderSize(2);
   c_2->SetTickx(1);
   c_2->SetTicky(1);
   c_2->SetFrameBorderMode(0);
   c_2->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1004[6] = {
   72.66343,
   112.9514,
   152.9971,
   193.8575,
   234.1913,
   274.7282};
   Double_t Graph0_fy1004[6] = {
   0.02688635,
   0.01902855,
   0.0148665,
   0.01268887,
   0.01110068,
   0.0101802};
   Double_t Graph0_fex1004[6] = {
   0.1252653,
   0.1084254,
   0.1160505,
   0.1456138,
   0.2102707,
   0.343635};
   Double_t Graph0_fey1004[6] = {
   0.0002364892,
   0.0001456843,
   0.0001187636,
   0.0001256567,
   0.0001732021,
   0.0002563452};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1004,Graph0_fy1004,Graph0_fex1004,Graph0_fey1004);
   gre->SetName("Graph0");
   gre->SetTitle("run530167");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph_Graph010011004 = new TH1F("Graph_Graph_Graph010011004","run530167",100,52.2848,295.3252);
   Graph_Graph_Graph010011004->SetMinimum(0.002);
   Graph_Graph_Graph010011004->SetMaximum(0.02884274);
   Graph_Graph_Graph010011004->SetDirectory(0);
   Graph_Graph_Graph010011004->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph_Graph010011004->SetLineColor(ci);
   Graph_Graph_Graph010011004->SetLineWidth(2);
   Graph_Graph_Graph010011004->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph_Graph010011004->GetXaxis()->SetRange(0,101);
   Graph_Graph_Graph010011004->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph010011004->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph010011004->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph010011004->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011004->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph_Graph010011004->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph010011004->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph010011004->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph010011004->GetYaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011004->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph010011004->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph_Graph010011004->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010011004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph010011004);
   
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.73,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 1.63567 #pm 0.0841535 ");
   ptstats_LaTex = ptstats->AddText("b [ns#bulletpC^{0.5}] = 0.12418 #pm 0.0168151 ");
   ptstats_LaTex = ptstats->AddText("c [ns]   = 0.00308393 #pm 0.00233949 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(11);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   
   TF1 *fitf1006 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",49.85439,297.7557, TF1::EAddToList::kNo);
   fitf1006->SetFillColor(19);
   fitf1006->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1006->SetLineColor(ci);
   fitf1006->SetLineWidth(3);
   fitf1006->SetChisquare(2.864768);
   fitf1006->SetNDF(3);
   fitf1006->GetXaxis()->SetLabelFont(42);
   fitf1006->GetXaxis()->SetLabelSize(0.05);
   fitf1006->GetXaxis()->SetTitleSize(0.05);
   fitf1006->GetXaxis()->SetTitleOffset(1);
   fitf1006->GetYaxis()->SetLabelFont(42);
   fitf1006->GetYaxis()->SetLabelSize(0.05);
   fitf1006->GetYaxis()->SetTitleSize(0.05);
   fitf1006->GetYaxis()->SetTitleOffset(1);
   fitf1006->SetParameter(0,1.635671);
   fitf1006->SetParError(0,0.08415347);
   fitf1006->SetParLimits(0,0,0);
   fitf1006->SetParameter(1,0.1241801);
   fitf1006->SetParError(1,0.01681511);
   fitf1006->SetParLimits(1,0,0);
   fitf1006->SetParameter(2,0.003083926);
   fitf1006->SetParError(2,0.002339492);
   fitf1006->SetParLimits(2,0,0);
   fitf1006->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1006);
   gre->Draw("ap");
   TGaxis *gaxis = new TGaxis(60,0.006,290,0.006,148.8,719.2,510,"-");
   gaxis->SetLabelOffset(0.005);
   gaxis->SetLabelSize(0.03);
   gaxis->SetTickSize(0.03);
   gaxis->SetGridLength(0);
   gaxis->SetTitleOffset(-1.1);
   gaxis->SetTitleSize(0.04);
   gaxis->SetTitleColor(600);
   gaxis->SetTitleFont(62);
   gaxis->SetTitle("N_{pe}");

   ci = TColor::GetColor("#0000ff");
   gaxis->SetLabelColor(ci);

   ci = TColor::GetColor("#0000ff");
   gaxis->SetLineColor(ci);
   gaxis->Draw();
   c_2->Modified();
   c_2->cd();
   c_2->SetSelected(c_2);
}
