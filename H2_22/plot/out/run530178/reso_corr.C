void reso_corr()
{
//=========Macro generated from canvas: c_5/c_5
//=========  (Wed Oct 26 14:38:22 2022) by ROOT version 6.24/06
   TCanvas *c_5 = new TCanvas("c_5", "c_5",0,0,600,450);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_5->SetHighLightColor(2);
   c_5->Range(16.34721,0.001860151,332.1538,0.08325863);
   c_5->SetFillColor(0);
   c_5->SetBorderMode(0);
   c_5->SetBorderSize(2);
   c_5->SetTickx(1);
   c_5->SetTicky(1);
   c_5->SetFrameBorderMode(0);
   c_5->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[6] = {
   71.37773,
   113.6012,
   154.6275,
   196.0011,
   236.4267,
   277.1248};
   Double_t Graph0_fy1001[6] = {
   0.06901215,
   0.04821484,
   0.04237135,
   0.03461149,
   0.03264784,
   0.03036197};
   Double_t Graph0_fex1001[6] = {
   0.3319877,
   0.2768332,
   0.2502175,
   0.2467299,
   0.2614082,
   0.3304662};
   Double_t Graph0_fey1001[6] = {
   0.001967237,
   0.001062333,
   0.0008038069,
   0.0005820698,
   0.0006383638,
   0.0007765887};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("run530178");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","run530178",100,50.40479,298.0962);
   Graph_Graph01001->SetMinimum(0.01);
   Graph_Graph01001->SetMaximum(0.07511878);
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
   
   
   TF1 *fitf1002 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",50.40479,298.0962, TF1::EAddToList::kNo);
   fitf1002->SetFillColor(19);
   fitf1002->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1002->SetLineColor(ci);
   fitf1002->SetLineWidth(3);
   fitf1002->SetChisquare(8.823096);
   fitf1002->SetNDF(3);
   fitf1002->GetXaxis()->SetLabelFont(42);
   fitf1002->GetXaxis()->SetLabelSize(0.05);
   fitf1002->GetXaxis()->SetTitleSize(0.05);
   fitf1002->GetXaxis()->SetTitleOffset(1);
   fitf1002->GetYaxis()->SetLabelFont(42);
   fitf1002->GetYaxis()->SetLabelSize(0.05);
   fitf1002->GetYaxis()->SetTitleSize(0.05);
   fitf1002->GetYaxis()->SetTitleOffset(1);
   fitf1002->SetParameter(0,3.78453);
   fitf1002->SetParError(0,0.5841538);
   fitf1002->SetParLimits(0,0,0);
   fitf1002->SetParameter(1,0.3379148);
   fitf1002->SetParError(1,0.09135117);
   fitf1002->SetParLimits(1,0,0);
   fitf1002->SetParameter(2,0.01762413);
   fitf1002->SetParError(2,0.005506108);
   fitf1002->SetParLimits(2,0,0);
   fitf1002->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1002);
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.69,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 3.78453 #pm 0.584154 ");
   ptstats_LaTex = ptstats->AddText("b [ns#bulletpC^{0.5}] = 0.337915 #pm 0.0913512 ");
   ptstats_LaTex = ptstats->AddText("c [ns]   = 0.0176241 #pm 0.00550611 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(11);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   TGaxis *gaxis = new TGaxis(60,0.02,290,0.02,297.6,1438.4,510,"-");
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
   c_5->Modified();
   c_5->cd();
   c_5->SetSelected(c_5);
}
