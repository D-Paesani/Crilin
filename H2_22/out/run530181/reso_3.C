void reso_3()
{
//=========Macro generated from canvas: c_2/c_2
//=========  (Wed Oct 12 16:48:57 2022) by ROOT version 6.24/06
   TCanvas *c_2 = new TCanvas("c_2", "c_2",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_2->SetHighLightColor(2);
   c_2->Range(18.28202,-0.004711032,330.8241,0.06239929);
   c_2->SetFillColor(0);
   c_2->SetBorderMode(0);
   c_2->SetBorderSize(2);
   c_2->SetTickx(1);
   c_2->SetTicky(1);
   c_2->SetFrameBorderMode(0);
   c_2->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1010[6] = {
   72.56741,
   113.5945,
   154.2022,
   195.3034,
   235.7215,
   276.5234};
   Double_t Graph0_fy1010[6] = {
   0.05185683,
   0.03596227,
   0.0277859,
   0.02351517,
   0.02083476,
   0.01987994};
   Double_t Graph0_fex1010[6] = {
   0.1522769,
   0.1178733,
   0.105455,
   0.1062935,
   0.1265002,
   0.167682};
   Double_t Graph0_fey1010[6] = {
   0.0005556132,
   0.0002736598,
   0.0001866656,
   0.0001642994,
   0.000169693,
   0.0002256549};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1010,Graph0_fy1010,Graph0_fex1010,Graph0_fey1010);
   gre->SetName("Graph0");
   gre->SetTitle("run530181");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph_Graph010071010 = new TH1F("Graph_Graph_Graph010071010","run530181",100,51.98755,297.1186);
   Graph_Graph_Graph010071010->SetMinimum(0.002);
   Graph_Graph_Graph010071010->SetMaximum(0.05568825);
   Graph_Graph_Graph010071010->SetDirectory(0);
   Graph_Graph_Graph010071010->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph_Graph010071010->SetLineColor(ci);
   Graph_Graph_Graph010071010->SetLineWidth(2);
   Graph_Graph_Graph010071010->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph_Graph010071010->GetXaxis()->SetRange(0,101);
   Graph_Graph_Graph010071010->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph010071010->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph010071010->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph010071010->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph010071010->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010071010->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph_Graph010071010->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph010071010->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph010071010->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph010071010->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph010071010->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph010071010->GetYaxis()->SetTitleOffset(1);
   Graph_Graph_Graph010071010->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph010071010->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph_Graph010071010->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph_Graph010071010->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph_Graph010071010->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph010071010->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph010071010);
   
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.73,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 3.64956 #pm 0.129965 ");
   ptstats_LaTex = ptstats->AddText("b [ns#bulletpC^{0.5}] = 0.0603274 #pm 0.103952 ");
   ptstats_LaTex = ptstats->AddText("c [ns]   = 0.0137814 #pm 0.00138919 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(11);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   
   TF1 *fitf1012 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",49.53624,299.5699, TF1::EAddToList::kNo);
   fitf1012->SetFillColor(19);
   fitf1012->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1012->SetLineColor(ci);
   fitf1012->SetLineWidth(3);
   fitf1012->SetChisquare(12.6819);
   fitf1012->SetNDF(3);
   fitf1012->GetXaxis()->SetLabelFont(42);
   fitf1012->GetXaxis()->SetLabelOffset(0.015);
   fitf1012->GetXaxis()->SetLabelSize(0.05);
   fitf1012->GetXaxis()->SetTitleSize(0.05);
   fitf1012->GetXaxis()->SetTitleOffset(1);
   fitf1012->GetYaxis()->SetLabelFont(42);
   fitf1012->GetYaxis()->SetLabelOffset(0.015);
   fitf1012->GetYaxis()->SetLabelSize(0.05);
   fitf1012->GetYaxis()->SetTitleSize(0.05);
   fitf1012->GetYaxis()->SetTickLength(0.02);
   fitf1012->GetYaxis()->SetTitleOffset(1);
   fitf1012->SetParameter(0,3.649563);
   fitf1012->SetParError(0,0.1299647);
   fitf1012->SetParLimits(0,0,0);
   fitf1012->SetParameter(1,0.06032745);
   fitf1012->SetParError(1,0.1039516);
   fitf1012->SetParLimits(1,0,0);
   fitf1012->SetParameter(2,0.01378138);
   fitf1012->SetParError(2,0.001389188);
   fitf1012->SetParLimits(2,0,0);
   fitf1012->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1012);
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
