#ifdef __CLING__
#pragma cling optimize(0)
#endif
void resocorr_2par_down()
{
//=========Macro generated from canvas: c_8/c_8
//=========  (Tue Dec 20 15:52:24 2022) by ROOT version 6.26/06
   TCanvas *c_8 = new TCanvas("c_8", "c_8",0,0,600,400);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_8->SetHighLightColor(2);
   c_8->Range(17.67763,0.00223104,331.0766,0.04992063);
   c_8->SetFillColor(0);
   c_8->SetBorderMode(0);
   c_8->SetBorderSize(2);
   c_8->SetTickx(1);
   c_8->SetTicky(1);
   c_8->SetFrameBorderMode(0);
   c_8->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1017[6] = {
   72.12155,
   113.0183,
   153.5977,
   194.9449,
   235.5299,
   276.5475};
   Double_t Graph0_fy1017[6] = {
   0.04272248,
   0.03449516,
   0.02994535,
   0.02783404,
   0.02530229,
   0.02378239};
   Double_t Graph0_fex1017[6] = {
   0.1624014,
   0.1411876,
   0.1377717,
   0.1530891,
   0.1798758,
   0.2476006};
   Double_t Graph0_fey1017[6] = {
   0.0004525022,
   0.0003077256,
   0.0002514192,
   0.0002381821,
   0.0002781587,
   0.000374349};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1017,Graph0_fy1017,Graph0_fex1017,Graph0_fey1017);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01017 = new TH1F("Graph_Graph01017","run530164",100,51.47556,297.2786);
   Graph_Graph01017->SetMinimum(0.007);
   Graph_Graph01017->SetMaximum(0.04515168);
   Graph_Graph01017->SetDirectory(0);
   Graph_Graph01017->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01017->SetLineColor(ci);
   Graph_Graph01017->SetLineWidth(2);
   Graph_Graph01017->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01017->GetXaxis()->SetRange(0,101);
   Graph_Graph01017->GetXaxis()->SetLabelFont(42);
   Graph_Graph01017->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01017->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01017->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01017->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01017->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01017->GetYaxis()->SetLabelFont(42);
   Graph_Graph01017->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01017->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01017->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01017->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01017->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01017->GetZaxis()->SetLabelFont(42);
   Graph_Graph01017->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01017->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01017->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01017->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01017->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01017);
   
   
   TF1 *fitf1018 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",51.47556,297.2786, TF1::EAddToList::kNo);
   fitf1018->SetFillColor(19);
   fitf1018->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1018->SetLineColor(ci);
   fitf1018->SetLineWidth(3);
   fitf1018->SetChisquare(60.38861);
   fitf1018->SetNDF(4);
   fitf1018->GetXaxis()->SetLabelFont(42);
   fitf1018->GetXaxis()->SetLabelOffset(0.015);
   fitf1018->GetXaxis()->SetLabelSize(0.05);
   fitf1018->GetXaxis()->SetTitleSize(0.05);
   fitf1018->GetXaxis()->SetTitleOffset(1);
   fitf1018->GetYaxis()->SetLabelFont(42);
   fitf1018->GetYaxis()->SetLabelOffset(0.015);
   fitf1018->GetYaxis()->SetLabelSize(0.05);
   fitf1018->GetYaxis()->SetTitleSize(0.05);
   fitf1018->GetYaxis()->SetTickLength(0.02);
   fitf1018->GetYaxis()->SetTitleOffset(1);
   fitf1018->SetParameter(0,2.721106);
   fitf1018->SetParError(0,0.03920786);
   fitf1018->SetParLimits(0,0,0);
   fitf1018->SetParameter(1,0.02338203);
   fitf1018->SetParError(1,0.0002243653);
   fitf1018->SetParLimits(1,0,0);
   fitf1018->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1018);
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
   c_8->Modified();
   c_8->cd();
   c_8->SetSelected(c_8);
}
