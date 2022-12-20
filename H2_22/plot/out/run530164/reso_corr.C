#ifdef __CLING__
#pragma cling optimize(0)
#endif
void reso_corr()
{
//=========Macro generated from canvas: c_5/c_5
//=========  (Tue Dec 20 10:26:34 2022) by ROOT version 6.26/06
   TCanvas *c_5 = new TCanvas("c_5", "c_5",0,0,600,450);
   gStyle->SetOptFit(1);
   c_5->SetHighLightColor(2);
   c_5->Range(17.62074,0.004586664,331.0982,0.05872002);
   c_5->SetFillColor(0);
   c_5->SetBorderMode(0);
   c_5->SetBorderSize(2);
   c_5->SetFrameBorderMode(0);
   c_5->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[6] = {
   72.02609,
   113.1542,
   153.7091,
   194.9694,
   235.621,
   276.6353};
   Double_t Graph0_fy1001[6] = {
   0.05017516,
   0.03805071,
   0.03183992,
   0.02768889,
   0.02441569,
   0.02280666};
   Double_t Graph0_fex1001[6] = {
   0.1102193,
   0.09619089,
   0.09293387,
   0.1019641,
   0.1224485,
   0.1678579};
   Double_t Graph0_fey1001[6] = {
   0.0003368058,
   0.0002244692,
   0.0001890733,
   0.0001813537,
   0.0001928322,
   0.0002419306};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","run530164",100,51.42714,297.2918);
   Graph_Graph01001->SetMinimum(0.01);
   Graph_Graph01001->SetMaximum(0.05330669);
   Graph_Graph01001->SetDirectory(0);
   Graph_Graph01001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01001->SetLineColor(ci);
   Graph_Graph01001->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01001->GetXaxis()->SetRange(0,101);
   Graph_Graph01001->GetXaxis()->SetLabelFont(42);
   Graph_Graph01001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetXaxis()->SetTitleFont(42);
   Graph_Graph01001->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01001->GetYaxis()->SetLabelFont(42);
   Graph_Graph01001->GetYaxis()->SetTitleFont(42);
   Graph_Graph01001->GetZaxis()->SetLabelFont(42);
   Graph_Graph01001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01001);
   
   
   TF1 *fitf1002 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",51.42714,297.2918, TF1::EAddToList::kNo);
   fitf1002->SetFillColor(19);
   fitf1002->SetFillStyle(0);
   fitf1002->SetLineColor(2);
   fitf1002->SetLineWidth(2);
   fitf1002->SetChisquare(6.233969);
   fitf1002->SetNDF(3);
   fitf1002->GetXaxis()->SetLabelFont(42);
   fitf1002->GetXaxis()->SetTitleOffset(1);
   fitf1002->GetXaxis()->SetTitleFont(42);
   fitf1002->GetYaxis()->SetLabelFont(42);
   fitf1002->GetYaxis()->SetTitleFont(42);
   fitf1002->SetParameter(0,1.979009);
   fitf1002->SetParError(0,0.07180611);
   fitf1002->SetParLimits(0,0,0);
   fitf1002->SetParameter(1,0.3583861);
   fitf1002->SetParError(1,0.003051833);
   fitf1002->SetParLimits(1,0,0);
   fitf1002->SetParameter(2,6.694573e-08);
   fitf1002->SetParError(2,0.003739031);
   fitf1002->SetParLimits(2,0,0);
   fitf1002->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1002);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 1.97901 #pm 0.0718061 ");
   ptstats_LaTex = ptstats->AddText("b [ns#bulletpC^{0.5}] = 0.358386 #pm 0.00305183 ");
   ptstats_LaTex = ptstats->AddText("c [ns]   = 6.69457e-08 #pm 0.00373903 ");
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
   
   TPaveText *pt = new TPaveText(0.398557,0.94,0.601443,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("run530164");
   pt->Draw();
   c_5->Modified();
   c_5->cd();
   c_5->SetSelected(c_5);
}
