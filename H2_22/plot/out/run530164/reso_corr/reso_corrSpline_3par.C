#ifdef __CLING__
#pragma cling optimize(0)
#endif
void reso_corrSpline_3par()
{
//=========Macro generated from canvas: c_12/c_12
//=========  (Tue Dec 20 10:34:04 2022) by ROOT version 6.26/06
   TCanvas *c_12 = new TCanvas("c_12", "c_12",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_12->SetHighLightColor(2);
   c_12->Range(17.61747,0.001661882,331.0989,0.05504306);
   c_12->SetFillColor(0);
   c_12->SetBorderMode(0);
   c_12->SetBorderSize(2);
   c_12->SetTickx(1);
   c_12->SetTicky(1);
   c_12->SetFrameBorderMode(0);
   c_12->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1007[6] = {
   72.02349,
   113.1542,
   153.7091,
   194.9694,
   235.621,
   276.6353};
   Double_t Graph0_fy1007[6] = {
   0.04702992,
   0.03515151,
   0.03021876,
   0.02737166,
   0.02502779,
   0.02412572};
   Double_t Graph0_fex1007[6] = {
   0.1102177,
   0.09619089,
   0.09293387,
   0.1019641,
   0.1224485,
   0.1678579};
   Double_t Graph0_fey1007[6] = {
   0.0003273759,
   0.0002071802,
   0.0001709335,
   0.0001656406,
   0.0001829467,
   0.0002448009};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1007,Graph0_fy1007,Graph0_fex1007,Graph0_fey1007);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01007 = new TH1F("Graph_Graph01007","run530164",100,51.42429,297.2921);
   Graph_Graph01007->SetMinimum(0.007);
   Graph_Graph01007->SetMaximum(0.04970494);
   Graph_Graph01007->SetDirectory(0);
   Graph_Graph01007->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01007->SetLineColor(ci);
   Graph_Graph01007->SetLineWidth(2);
   Graph_Graph01007->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01007->GetXaxis()->SetRange(0,101);
   Graph_Graph01007->GetXaxis()->SetLabelFont(42);
   Graph_Graph01007->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01007->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01007->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01007->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01007->GetYaxis()->SetLabelFont(42);
   Graph_Graph01007->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01007->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01007->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01007->GetZaxis()->SetLabelFont(42);
   Graph_Graph01007->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01007->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01007);
   
   
   TF1 *fitf1008 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",51.42429,297.2921, TF1::EAddToList::kNo);
   fitf1008->SetFillColor(19);
   fitf1008->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1008->SetLineColor(ci);
   fitf1008->SetLineWidth(3);
   fitf1008->SetChisquare(5.044019);
   fitf1008->SetNDF(3);
   fitf1008->GetXaxis()->SetLabelFont(42);
   fitf1008->GetXaxis()->SetLabelSize(0.05);
   fitf1008->GetXaxis()->SetTitleSize(0.05);
   fitf1008->GetXaxis()->SetTitleOffset(1);
   fitf1008->GetYaxis()->SetLabelFont(42);
   fitf1008->GetYaxis()->SetLabelSize(0.05);
   fitf1008->GetYaxis()->SetTitleSize(0.05);
   fitf1008->GetYaxis()->SetTitleOffset(1);
   fitf1008->SetParameter(0,2.41887);
   fitf1008->SetParError(0,0.1371787);
   fitf1008->SetParLimits(0,0,0);
   fitf1008->SetParameter(1,0.2364396);
   fitf1008->SetParError(1,0.02163053);
   fitf1008->SetParLimits(1,0,0);
   fitf1008->SetParameter(2,0.01725398);
   fitf1008->SetParError(2,0.001013667);
   fitf1008->SetParLimits(2,0,0);
   fitf1008->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1008);
   
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
   c_12->Modified();
   c_12->cd();
   c_12->SetSelected(c_12);
}
