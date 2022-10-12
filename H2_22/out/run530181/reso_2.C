void reso_2()
{
//=========Macro generated from canvas: c_1/c_1
//=========  (Wed Oct 12 17:11:11 2022) by ROOT version 6.24/06
   TCanvas *c_1 = new TCanvas("c_1", "c_1",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_1->SetHighLightColor(2);
   c_1->Range(18.28202,-0.003211032,330.8241,0.06223262);
   c_1->SetFillColor(0);
   c_1->SetBorderMode(0);
   c_1->SetBorderSize(2);
   c_1->SetTickx(1);
   c_1->SetTicky(1);
   c_1->SetFrameBorderMode(0);
   c_1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1049[6] = {
   72.56741,
   113.5945,
   154.2022,
   195.3034,
   235.7215,
   276.5234};
   Double_t Graph0_fy1049[6] = {
   0.05185683,
   0.03596227,
   0.0277859,
   0.02351517,
   0.02083476,
   0.01987994};
   Double_t Graph0_fex1049[6] = {
   0.1522769,
   0.1178733,
   0.105455,
   0.1062935,
   0.1265002,
   0.167682};
   Double_t Graph0_fey1049[6] = {
   0.0005556132,
   0.0002736598,
   0.0001866656,
   0.0001642994,
   0.000169693,
   0.0002256549};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1049,Graph0_fy1049,Graph0_fex1049,Graph0_fey1049);
   gre->SetName("Graph0");
   gre->SetTitle("run530181");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01049 = new TH1F("Graph_Graph01049","run530181",100,51.98755,297.1186);
   Graph_Graph01049->SetMinimum(0.003333333);
   Graph_Graph01049->SetMaximum(0.05568825);
   Graph_Graph01049->SetDirectory(0);
   Graph_Graph01049->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01049->SetLineColor(ci);
   Graph_Graph01049->SetLineWidth(2);
   Graph_Graph01049->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01049->GetXaxis()->SetRange(0,101);
   Graph_Graph01049->GetXaxis()->SetLabelFont(42);
   Graph_Graph01049->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01049->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01049->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01049->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01049->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01049->GetYaxis()->SetLabelFont(42);
   Graph_Graph01049->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01049->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01049->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01049->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01049->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01049->GetZaxis()->SetLabelFont(42);
   Graph_Graph01049->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01049->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01049->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01049->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01049->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01049);
   
   
   TF1 *fitf1050 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",49.53624,299.5699, TF1::EAddToList::kNo);
   fitf1050->SetFillColor(19);
   fitf1050->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1050->SetLineColor(ci);
   fitf1050->SetLineWidth(3);
   fitf1050->SetChisquare(12.76888);
   fitf1050->SetNDF(4);
   fitf1050->GetXaxis()->SetLabelFont(42);
   fitf1050->GetXaxis()->SetLabelOffset(0.015);
   fitf1050->GetXaxis()->SetLabelSize(0.05);
   fitf1050->GetXaxis()->SetTitleSize(0.05);
   fitf1050->GetXaxis()->SetTitleOffset(1);
   fitf1050->GetYaxis()->SetLabelFont(42);
   fitf1050->GetYaxis()->SetLabelOffset(0.015);
   fitf1050->GetYaxis()->SetLabelSize(0.05);
   fitf1050->GetYaxis()->SetTitleSize(0.05);
   fitf1050->GetYaxis()->SetTickLength(0.02);
   fitf1050->GetYaxis()->SetTitleOffset(1);
   fitf1050->SetParameter(0,3.686055);
   fitf1050->SetParError(0,0.03008297);
   fitf1050->SetParLimits(0,0,0);
   fitf1050->SetParameter(1,0.01417196);
   fitf1050->SetParError(1,0.0002494932);
   fitf1050->SetParLimits(1,0,0);
   fitf1050->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1050);
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.73,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 3.68605 #pm 0.030083 ");
   ptstats_LaTex = ptstats->AddText("b [ns]   = 0.014172 #pm 0.000249493 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(11);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   TGaxis *gaxis = new TGaxis(60,0.01,290,0.01,297.6,1438.4,510,"-");
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
