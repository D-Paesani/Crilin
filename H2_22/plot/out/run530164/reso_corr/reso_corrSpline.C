#ifdef __CLING__
#pragma cling optimize(0)
#endif
void reso_corrSpline()
{
//=========Macro generated from canvas: c_11/c_11
//=========  (Tue Dec 20 10:34:04 2022) by ROOT version 6.26/06
   TCanvas *c_11 = new TCanvas("c_11", "c_11",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_11->SetHighLightColor(2);
   c_11->Range(17.61747,0.001661882,331.0989,0.05504306);
   c_11->SetFillColor(0);
   c_11->SetBorderMode(0);
   c_11->SetBorderSize(2);
   c_11->SetTickx(1);
   c_11->SetTicky(1);
   c_11->SetFrameBorderMode(0);
   c_11->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1004[6] = {
   72.02349,
   113.1542,
   153.7091,
   194.9694,
   235.621,
   276.6353};
   Double_t Graph0_fy1004[6] = {
   0.04702992,
   0.03515151,
   0.03021876,
   0.02737166,
   0.02502779,
   0.02412572};
   Double_t Graph0_fex1004[6] = {
   0.1102177,
   0.09619089,
   0.09293387,
   0.1019641,
   0.1224485,
   0.1678579};
   Double_t Graph0_fey1004[6] = {
   0.0003273759,
   0.0002071802,
   0.0001709335,
   0.0001656406,
   0.0001829467,
   0.0002448009};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1004,Graph0_fy1004,Graph0_fex1004,Graph0_fey1004);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01004 = new TH1F("Graph_Graph01004","run530164",100,51.42429,297.2921);
   Graph_Graph01004->SetMinimum(0.007);
   Graph_Graph01004->SetMaximum(0.04970494);
   Graph_Graph01004->SetDirectory(0);
   Graph_Graph01004->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01004->SetLineColor(ci);
   Graph_Graph01004->SetLineWidth(2);
   Graph_Graph01004->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01004->GetXaxis()->SetRange(0,101);
   Graph_Graph01004->GetXaxis()->SetLabelFont(42);
   Graph_Graph01004->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01004->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01004->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01004->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01004->GetYaxis()->SetLabelFont(42);
   Graph_Graph01004->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01004->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01004->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01004->GetZaxis()->SetLabelFont(42);
   Graph_Graph01004->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01004->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01004);
   
   
   TF1 *fitf1005 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",51.42429,297.2921, TF1::EAddToList::kNo);
   fitf1005->SetFillColor(19);
   fitf1005->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1005->SetLineColor(ci);
   fitf1005->SetLineWidth(3);
   fitf1005->SetChisquare(34.58564);
   fitf1005->SetNDF(4);
   fitf1005->GetXaxis()->SetLabelFont(42);
   fitf1005->GetXaxis()->SetLabelSize(0.05);
   fitf1005->GetXaxis()->SetTitleSize(0.05);
   fitf1005->GetXaxis()->SetTitleOffset(1);
   fitf1005->GetYaxis()->SetLabelFont(42);
   fitf1005->GetYaxis()->SetLabelSize(0.05);
   fitf1005->GetYaxis()->SetTitleSize(0.05);
   fitf1005->GetYaxis()->SetTitleOffset(1);
   fitf1005->SetParameter(0,3.064761);
   fitf1005->SetParError(0,0.02555011);
   fitf1005->SetParLimits(0,0,0);
   fitf1005->SetParameter(1,0.02202442);
   fitf1005->SetParError(1,0.0001624096);
   fitf1005->SetParLimits(1,0,0);
   fitf1005->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1005);
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.73,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 3.06476 #pm 0.0255501 ");
   ptstats_LaTex = ptstats->AddText("b [ns]   = 0.0220244 #pm 0.00016241 ");
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
   c_11->Modified();
   c_11->cd();
   c_11->SetSelected(c_11);
}
