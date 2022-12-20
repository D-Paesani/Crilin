#ifdef __CLING__
#pragma cling optimize(0)
#endif
void reso_corr()
{
//=========Macro generated from canvas: c_10/c_10
//=========  (Tue Dec 20 10:34:04 2022) by ROOT version 6.26/06
   TCanvas *c_10 = new TCanvas("c_10", "c_10",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_10->SetHighLightColor(2);
   c_10->Range(17.61875,0.001418979,331.1109,0.05722919);
   c_10->SetFillColor(0);
   c_10->SetBorderMode(0);
   c_10->SetBorderSize(2);
   c_10->SetTickx(1);
   c_10->SetTicky(1);
   c_10->SetFrameBorderMode(0);
   c_10->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[6] = {
   72.02746,
   113.1613,
   153.7298,
   194.9702,
   235.6497,
   276.6452};
   Double_t Graph0_fy1001[6] = {
   0.04888628,
   0.03765089,
   0.03229664,
   0.0288998,
   0.02625619,
   0.02513935};
   Double_t Graph0_fex1001[6] = {
   0.1110446,
   0.09668719,
   0.09336336,
   0.1022605,
   0.1227083,
   0.1680325};
   Double_t Graph0_fey1001[6] = {
   0.0003285091,
   0.0002210369,
   0.0001838237,
   0.0001768196,
   0.0002018218,
   0.0002583314};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","run530164",100,51.42673,297.3029);
   Graph_Graph01001->SetMinimum(0.007);
   Graph_Graph01001->SetMaximum(0.05164817);
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
   
   
   TF1 *fitf1002 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",51.42673,297.3029, TF1::EAddToList::kNo);
   fitf1002->SetFillColor(19);
   fitf1002->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1002->SetLineColor(ci);
   fitf1002->SetLineWidth(3);
   fitf1002->SetChisquare(3.538391);
   fitf1002->SetNDF(3);
   fitf1002->GetXaxis()->SetLabelFont(42);
   fitf1002->GetXaxis()->SetLabelSize(0.05);
   fitf1002->GetXaxis()->SetTitleSize(0.05);
   fitf1002->GetXaxis()->SetTitleOffset(1);
   fitf1002->GetYaxis()->SetLabelFont(42);
   fitf1002->GetYaxis()->SetLabelSize(0.05);
   fitf1002->GetYaxis()->SetTitleSize(0.05);
   fitf1002->GetYaxis()->SetTitleOffset(1);
   fitf1002->SetParameter(0,1.920803);
   fitf1002->SetParError(0,0.1876992);
   fitf1002->SetParLimits(0,0,0);
   fitf1002->SetParameter(1,0.3283187);
   fitf1002->SetParError(1,0.01718418);
   fitf1002->SetParLimits(1,0,0);
   fitf1002->SetParameter(2,0.01345885);
   fitf1002->SetParError(2,0.001441178);
   fitf1002->SetParLimits(2,0,0);
   fitf1002->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1002);
   
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
   TGaxis *gaxis = new TGaxis(60,0.014,290,0.014,148.8,719.2,510,"-");
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
   c_10->Modified();
   c_10->cd();
   c_10->SetSelected(c_10);
}
