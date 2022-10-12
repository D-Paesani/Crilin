void reso_corr_2pars()
{
//=========Macro generated from canvas: c_5/c_5
//=========  (Wed Oct 12 15:39:42 2022) by ROOT version 6.24/06
   TCanvas *c_5 = new TCanvas("c_5", "c_5",0,0,600,450);
   gStyle->SetOptFit(1);
   c_5->SetHighLightColor(2);
   c_5->Range(17.61875,0.01609726,331.1109,0.0551247);
   c_5->SetFillColor(0);
   c_5->SetBorderMode(0);
   c_5->SetBorderSize(2);
   c_5->SetFrameBorderMode(0);
   c_5->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1019[6] = {
   72.02746,
   113.1613,
   153.7298,
   194.9702,
   235.6497,
   276.6452};
   Double_t Graph0_fy1019[6] = {
   0.04857821,
   0.03750186,
   0.03257719,
   0.02930259,
   0.02681616,
   0.0262364};
   Double_t Graph0_fex1019[6] = {
   0.1110446,
   0.09668719,
   0.09336336,
   0.1022605,
   0.1227083,
   0.1680325};
   Double_t Graph0_fey1019[6] = {
   0.0003459683,
   0.0002220134,
   0.0001877895,
   0.0001802359,
   0.0002086874,
   0.0002899965};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1019,Graph0_fy1019,Graph0_fex1019,Graph0_fey1019);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01019 = new TH1F("Graph_Graph01019","run530164",100,51.42673,297.3029);
   Graph_Graph01019->SetMinimum(0.02);
   Graph_Graph01019->SetMaximum(0.05122196);
   Graph_Graph01019->SetDirectory(0);
   Graph_Graph01019->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01019->SetLineColor(ci);
   Graph_Graph01019->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01019->GetXaxis()->SetRange(0,101);
   Graph_Graph01019->GetXaxis()->SetLabelFont(42);
   Graph_Graph01019->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01019->GetXaxis()->SetTitleFont(42);
   Graph_Graph01019->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01019->GetYaxis()->SetLabelFont(42);
   Graph_Graph01019->GetYaxis()->SetTitleFont(42);
   Graph_Graph01019->GetZaxis()->SetLabelFont(42);
   Graph_Graph01019->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01019->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01019);
   
   
   TF1 *fitf1020 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",51.42673,297.3029, TF1::EAddToList::kNo);
   fitf1020->SetFillColor(19);
   fitf1020->SetFillStyle(0);
   fitf1020->SetLineColor(2);
   fitf1020->SetLineWidth(2);
   fitf1020->SetChisquare(64.89956);
   fitf1020->SetNDF(4);
   fitf1020->GetXaxis()->SetLabelFont(42);
   fitf1020->GetXaxis()->SetTitleOffset(1);
   fitf1020->GetXaxis()->SetTitleFont(42);
   fitf1020->GetYaxis()->SetLabelFont(42);
   fitf1020->GetYaxis()->SetTitleFont(42);
   fitf1020->SetParameter(0,3.14699);
   fitf1020->SetParError(0,0.0282885);
   fitf1020->SetParLimits(0,0,0);
   fitf1020->SetParameter(1,0.02427334);
   fitf1020->SetParError(1,0.000176433);
   fitf1020->SetParLimits(1,0,0);
   fitf1020->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1020);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.815,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 3.14699 #pm 0.0282885 ");
   ptstats_LaTex = ptstats->AddText("b [ns]   = 0.0242733 #pm 0.000176433 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(11);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   TGaxis *gaxis = new TGaxis(60,0.024,290,0.024,148.8,719.2,510,"-");
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
