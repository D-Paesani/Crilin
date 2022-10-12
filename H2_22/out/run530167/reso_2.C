void reso_2()
{
//=========Macro generated from canvas: c_1/c_1
//=========  (Wed Oct 12 14:26:36 2022) by ROOT version 6.24/06
   TCanvas *c_1 = new TCanvas("c_1", "c_1",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_1->SetHighLightColor(2);
   c_1->Range(18.86673,-0.001355343,328.7433,0.03219808);
   c_1->SetFillColor(0);
   c_1->SetBorderMode(0);
   c_1->SetBorderSize(2);
   c_1->SetTickx(1);
   c_1->SetTicky(1);
   c_1->SetFrameBorderMode(0);
   c_1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[6] = {
   72.66343,
   112.9514,
   152.9971,
   193.8575,
   234.1913,
   274.7282};
   Double_t Graph0_fy1001[6] = {
   0.02688635,
   0.01902855,
   0.0148665,
   0.01268887,
   0.01110068,
   0.0101802};
   Double_t Graph0_fex1001[6] = {
   0.1252653,
   0.1084254,
   0.1160505,
   0.1456138,
   0.2102707,
   0.343635};
   Double_t Graph0_fey1001[6] = {
   0.0002364892,
   0.0001456843,
   0.0001187636,
   0.0001256567,
   0.0001732021,
   0.0002563452};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("run530167");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","run530167",100,52.2848,295.3252);
   Graph_Graph01001->SetMinimum(0.002);
   Graph_Graph01001->SetMaximum(0.02884274);
   Graph_Graph01001->SetDirectory(0);
   Graph_Graph01001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01001->SetLineColor(ci);
   Graph_Graph01001->SetLineWidth(2);
   Graph_Graph01001->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01001->GetXaxis()->SetRange(0,101);
   Graph_Graph01001->GetXaxis()->SetLabelFont(42);
   Graph_Graph01001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01001->GetYaxis()->SetLabelFont(42);
   Graph_Graph01001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01001->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetZaxis()->SetLabelFont(42);
   Graph_Graph01001->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01001);
   
   
   TF1 *fitf1002 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",49.85439,297.7557, TF1::EAddToList::kNo);
   fitf1002->SetFillColor(19);
   fitf1002->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1002->SetLineColor(ci);
   fitf1002->SetLineWidth(3);
   fitf1002->SetChisquare(16.31629);
   fitf1002->SetNDF(4);
   fitf1002->GetXaxis()->SetLabelFont(42);
   fitf1002->GetXaxis()->SetLabelSize(0.05);
   fitf1002->GetXaxis()->SetTitleSize(0.05);
   fitf1002->GetXaxis()->SetTitleOffset(1);
   fitf1002->GetYaxis()->SetLabelFont(42);
   fitf1002->GetYaxis()->SetLabelSize(0.05);
   fitf1002->GetYaxis()->SetTitleSize(0.05);
   fitf1002->GetYaxis()->SetTitleOffset(1);
   fitf1002->SetParameter(0,1.914926);
   fitf1002->SetParError(0,0.01679252);
   fitf1002->SetParLimits(0,0,0);
   fitf1002->SetParameter(1,0.007862912);
   fitf1002->SetParError(1,0.0001858054);
   fitf1002->SetParLimits(1,0,0);
   fitf1002->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1002);
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.73,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 1.91493 #pm 0.0167925 ");
   ptstats_LaTex = ptstats->AddText("b [ns]   = 0.00786291 #pm 0.000185805 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(11);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
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
   c_1->Modified();
   c_1->cd();
   c_1->SetSelected(c_1);
}
