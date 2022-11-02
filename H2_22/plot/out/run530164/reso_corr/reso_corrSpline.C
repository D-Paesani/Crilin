void reso_corrSpline()
{
//=========Macro generated from canvas: c_8/c_8
//=========  (Thu Oct 27 12:00:12 2022) by ROOT version 6.24/06
   TCanvas *c_8 = new TCanvas("c_8", "c_8",0,0,800,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_8->SetHighLightColor(2);
   c_8->Range(17.61747,0.001661882,331.0989,0.05504306);
   c_8->SetFillColor(0);
   c_8->SetBorderMode(0);
   c_8->SetBorderSize(2);
   c_8->SetTickx(1);
   c_8->SetTicky(1);
   c_8->SetFrameBorderMode(0);
   c_8->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1220[6] = {
   72.02349,
   113.1542,
   153.7091,
   194.9694,
   235.621,
   276.6353};
   Double_t Graph0_fy1220[6] = {
   0.04702992,
   0.03515151,
   0.03021876,
   0.02737166,
   0.02502779,
   0.02412572};
   Double_t Graph0_fex1220[6] = {
   0.1102177,
   0.09619089,
   0.09293387,
   0.1019641,
   0.1224485,
   0.1678579};
   Double_t Graph0_fey1220[6] = {
   0.0003273759,
   0.0002071802,
   0.0001709335,
   0.0001656406,
   0.0001829467,
   0.0002448009};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1220,Graph0_fy1220,Graph0_fex1220,Graph0_fey1220);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01220 = new TH1F("Graph_Graph01220","run530164",100,51.42429,297.2921);
   Graph_Graph01220->SetMinimum(0.007);
   Graph_Graph01220->SetMaximum(0.04970494);
   Graph_Graph01220->SetDirectory(0);
   Graph_Graph01220->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01220->SetLineColor(ci);
   Graph_Graph01220->SetLineWidth(2);
   Graph_Graph01220->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01220->GetXaxis()->SetRange(0,101);
   Graph_Graph01220->GetXaxis()->SetLabelFont(42);
   Graph_Graph01220->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01220->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01220->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01220->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01220->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01220->GetYaxis()->SetLabelFont(42);
   Graph_Graph01220->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01220->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01220->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01220->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01220->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01220->GetZaxis()->SetLabelFont(42);
   Graph_Graph01220->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01220->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01220->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01220->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01220->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01220);
   
   
   TF1 *fitf1221 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",51.42429,297.2921, TF1::EAddToList::kNo);
   fitf1221->SetFillColor(19);
   fitf1221->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1221->SetLineColor(ci);
   fitf1221->SetLineWidth(3);
   fitf1221->SetChisquare(34.58564);
   fitf1221->SetNDF(4);
   fitf1221->GetXaxis()->SetLabelFont(42);
   fitf1221->GetXaxis()->SetLabelOffset(0.015);
   fitf1221->GetXaxis()->SetLabelSize(0.05);
   fitf1221->GetXaxis()->SetTitleSize(0.05);
   fitf1221->GetXaxis()->SetTitleOffset(1);
   fitf1221->GetYaxis()->SetLabelFont(42);
   fitf1221->GetYaxis()->SetLabelOffset(0.015);
   fitf1221->GetYaxis()->SetLabelSize(0.05);
   fitf1221->GetYaxis()->SetTitleSize(0.05);
   fitf1221->GetYaxis()->SetTickLength(0.02);
   fitf1221->GetYaxis()->SetTitleOffset(1);
   fitf1221->SetParameter(0,3.064761);
   fitf1221->SetParError(0,0.02555011);
   fitf1221->SetParLimits(0,0,0);
   fitf1221->SetParameter(1,0.02202442);
   fitf1221->SetParError(1,0.0001624096);
   fitf1221->SetParLimits(1,0,0);
   fitf1221->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1221);
   
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
   c_8->Modified();
   c_8->cd();
   c_8->SetSelected(c_8);
}
