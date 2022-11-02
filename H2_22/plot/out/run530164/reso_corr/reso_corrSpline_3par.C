void reso_corrSpline_3par()
{
//=========Macro generated from canvas: c_9/c_9
//=========  (Thu Oct 27 12:00:13 2022) by ROOT version 6.24/06
   TCanvas *c_9 = new TCanvas("c_9", "c_9",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_9->SetHighLightColor(2);
   c_9->Range(17.61747,0.001661882,331.0989,0.05504306);
   c_9->SetFillColor(0);
   c_9->SetBorderMode(0);
   c_9->SetBorderSize(2);
   c_9->SetTickx(1);
   c_9->SetTicky(1);
   c_9->SetFrameBorderMode(0);
   c_9->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1223[6] = {
   72.02349,
   113.1542,
   153.7091,
   194.9694,
   235.621,
   276.6353};
   Double_t Graph0_fy1223[6] = {
   0.04702992,
   0.03515151,
   0.03021876,
   0.02737166,
   0.02502779,
   0.02412572};
   Double_t Graph0_fex1223[6] = {
   0.1102177,
   0.09619089,
   0.09293387,
   0.1019641,
   0.1224485,
   0.1678579};
   Double_t Graph0_fey1223[6] = {
   0.0003273759,
   0.0002071802,
   0.0001709335,
   0.0001656406,
   0.0001829467,
   0.0002448009};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1223,Graph0_fy1223,Graph0_fex1223,Graph0_fey1223);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01223 = new TH1F("Graph_Graph01223","run530164",100,51.42429,297.2921);
   Graph_Graph01223->SetMinimum(0.007);
   Graph_Graph01223->SetMaximum(0.04970494);
   Graph_Graph01223->SetDirectory(0);
   Graph_Graph01223->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01223->SetLineColor(ci);
   Graph_Graph01223->SetLineWidth(2);
   Graph_Graph01223->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01223->GetXaxis()->SetRange(0,101);
   Graph_Graph01223->GetXaxis()->SetLabelFont(42);
   Graph_Graph01223->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01223->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01223->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01223->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01223->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01223->GetYaxis()->SetLabelFont(42);
   Graph_Graph01223->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01223->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01223->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01223->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01223->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01223->GetZaxis()->SetLabelFont(42);
   Graph_Graph01223->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01223->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01223->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01223->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01223->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01223);
   
   
   TF1 *fitf1224 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",51.42429,297.2921, TF1::EAddToList::kNo);
   fitf1224->SetFillColor(19);
   fitf1224->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1224->SetLineColor(ci);
   fitf1224->SetLineWidth(3);
   fitf1224->SetChisquare(5.044019);
   fitf1224->SetNDF(3);
   fitf1224->GetXaxis()->SetLabelFont(42);
   fitf1224->GetXaxis()->SetLabelOffset(0.015);
   fitf1224->GetXaxis()->SetLabelSize(0.05);
   fitf1224->GetXaxis()->SetTitleSize(0.05);
   fitf1224->GetXaxis()->SetTitleOffset(1);
   fitf1224->GetYaxis()->SetLabelFont(42);
   fitf1224->GetYaxis()->SetLabelOffset(0.015);
   fitf1224->GetYaxis()->SetLabelSize(0.05);
   fitf1224->GetYaxis()->SetTitleSize(0.05);
   fitf1224->GetYaxis()->SetTickLength(0.02);
   fitf1224->GetYaxis()->SetTitleOffset(1);
   fitf1224->SetParameter(0,2.41887);
   fitf1224->SetParError(0,0.1371787);
   fitf1224->SetParLimits(0,0,0);
   fitf1224->SetParameter(1,0.2364396);
   fitf1224->SetParError(1,0.02163053);
   fitf1224->SetParLimits(1,0,0);
   fitf1224->SetParameter(2,0.01725398);
   fitf1224->SetParError(2,0.001013667);
   fitf1224->SetParLimits(2,0,0);
   fitf1224->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1224);
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.69,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 2.41887 #pm 0.137179 ");
   ptstats_LaTex = ptstats->AddText("b [ns#bulletpC^{0.5}] = 0.23644 #pm 0.0216305 ");
   ptstats_LaTex = ptstats->AddText("c [ns]   = 0.017254 #pm 0.00101367 ");
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
   c_9->Modified();
   c_9->cd();
   c_9->SetSelected(c_9);
}
