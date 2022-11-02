void reso_corr()
{
//=========Macro generated from canvas: c_7/c_7
//=========  (Thu Oct 27 12:00:12 2022) by ROOT version 6.24/06
   TCanvas *c_7 = new TCanvas("c_7", "c_7",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_7->SetHighLightColor(2);
   c_7->Range(17.61875,0.001418979,331.1109,0.05722919);
   c_7->SetFillColor(0);
   c_7->SetBorderMode(0);
   c_7->SetBorderSize(2);
   c_7->SetTickx(1);
   c_7->SetTicky(1);
   c_7->SetFrameBorderMode(0);
   c_7->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1217[6] = {
   72.02746,
   113.1613,
   153.7298,
   194.9702,
   235.6497,
   276.6452};
   Double_t Graph0_fy1217[6] = {
   0.04888628,
   0.03765089,
   0.03229664,
   0.0288998,
   0.02625619,
   0.02513935};
   Double_t Graph0_fex1217[6] = {
   0.1110446,
   0.09668719,
   0.09336336,
   0.1022605,
   0.1227083,
   0.1680325};
   Double_t Graph0_fey1217[6] = {
   0.0003285091,
   0.0002210369,
   0.0001838237,
   0.0001768196,
   0.0002018218,
   0.0002583314};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1217,Graph0_fy1217,Graph0_fex1217,Graph0_fey1217);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01217 = new TH1F("Graph_Graph01217","run530164",100,51.42673,297.3029);
   Graph_Graph01217->SetMinimum(0.007);
   Graph_Graph01217->SetMaximum(0.05164817);
   Graph_Graph01217->SetDirectory(0);
   Graph_Graph01217->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01217->SetLineColor(ci);
   Graph_Graph01217->SetLineWidth(2);
   Graph_Graph01217->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01217->GetXaxis()->SetRange(0,101);
   Graph_Graph01217->GetXaxis()->SetLabelFont(42);
   Graph_Graph01217->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01217->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01217->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01217->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01217->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01217->GetYaxis()->SetLabelFont(42);
   Graph_Graph01217->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01217->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01217->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01217->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01217->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01217->GetZaxis()->SetLabelFont(42);
   Graph_Graph01217->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01217->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01217->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01217->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01217->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01217);
   
   
   TF1 *fitf1218 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",51.42673,297.3029, TF1::EAddToList::kNo);
   fitf1218->SetFillColor(19);
   fitf1218->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1218->SetLineColor(ci);
   fitf1218->SetLineWidth(3);
   fitf1218->SetChisquare(3.538391);
   fitf1218->SetNDF(3);
   fitf1218->GetXaxis()->SetLabelFont(42);
   fitf1218->GetXaxis()->SetLabelOffset(0.015);
   fitf1218->GetXaxis()->SetLabelSize(0.05);
   fitf1218->GetXaxis()->SetTitleSize(0.05);
   fitf1218->GetXaxis()->SetTitleOffset(1);
   fitf1218->GetYaxis()->SetLabelFont(42);
   fitf1218->GetYaxis()->SetLabelOffset(0.015);
   fitf1218->GetYaxis()->SetLabelSize(0.05);
   fitf1218->GetYaxis()->SetTitleSize(0.05);
   fitf1218->GetYaxis()->SetTickLength(0.02);
   fitf1218->GetYaxis()->SetTitleOffset(1);
   fitf1218->SetParameter(0,1.920803);
   fitf1218->SetParError(0,0.1876992);
   fitf1218->SetParLimits(0,0,0);
   fitf1218->SetParameter(1,0.3283187);
   fitf1218->SetParError(1,0.01718418);
   fitf1218->SetParLimits(1,0,0);
   fitf1218->SetParameter(2,0.01345885);
   fitf1218->SetParError(2,0.001441178);
   fitf1218->SetParLimits(2,0,0);
   fitf1218->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1218);
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.69,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ps#bulletpC] = 1.9208 #pm 0.187699 ");
   ptstats_LaTex = ptstats->AddText("b [ps#bulletpC^{0.5}] = 0.328319 #pm 0.0171842 ");
   ptstats_LaTex = ptstats->AddText("c [ps]   = 0.0134589 #pm 0.00144118 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(11);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   TGaxis *gaxis = new TGaxis(60,0.014,290,0.014,297.6,1438.4,510,"-");
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
   c_7->Modified();
   c_7->cd();
   c_7->SetSelected(c_7);
}
