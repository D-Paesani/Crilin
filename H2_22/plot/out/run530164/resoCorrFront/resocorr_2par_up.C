#ifdef __CLING__
#pragma cling optimize(0)
#endif
void resocorr_2par_up()
{
//=========Macro generated from canvas: c_8/c_8
//=========  (Tue Dec 20 15:51:33 2022) by ROOT version 6.26/06
   TCanvas *c_8 = new TCanvas("c_8", "c_8",0,0,600,400);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_8->SetHighLightColor(2);
   c_8->Range(17.61706,0.002312612,331.5883,0.04918649);
   c_8->SetFillColor(0);
   c_8->SetBorderMode(0);
   c_8->SetBorderSize(2);
   c_8->SetTickx(1);
   c_8->SetTicky(1);
   c_8->SetFrameBorderMode(0);
   c_8->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1015[6] = {
   72.18467,
   113.3336,
   153.6888,
   195.2029,
   235.8502,
   276.9415};
   Double_t Graph0_fy1015[6] = {
   0.0420364,
   0.03309898,
   0.03012591,
   0.02741006,
   0.02468111,
   0.02366576};
   Double_t Graph0_fex1015[6] = {
   0.1869765,
   0.1623693,
   0.1522361,
   0.1642263,
   0.1969102,
   0.2660887};
   Double_t Graph0_fey1015[6] = {
   0.0005299862,
   0.0003344581,
   0.0002847748,
   0.0002835312,
   0.0003003843,
   0.0004264554};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1015,Graph0_fy1015,Graph0_fex1015,Graph0_fey1015);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01015 = new TH1F("Graph_Graph01015","run530164",100,51.4767,297.7286);
   Graph_Graph01015->SetMinimum(0.007);
   Graph_Graph01015->SetMaximum(0.0444991);
   Graph_Graph01015->SetDirectory(0);
   Graph_Graph01015->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01015->SetLineColor(ci);
   Graph_Graph01015->SetLineWidth(2);
   Graph_Graph01015->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01015->GetXaxis()->SetRange(0,101);
   Graph_Graph01015->GetXaxis()->SetLabelFont(42);
   Graph_Graph01015->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01015->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01015->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01015->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01015->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01015->GetYaxis()->SetLabelFont(42);
   Graph_Graph01015->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01015->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01015->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01015->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01015->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01015->GetZaxis()->SetLabelFont(42);
   Graph_Graph01015->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01015->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01015->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01015->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01015->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01015);
   
   
   TF1 *fitf1016 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",51.4767,297.7286, TF1::EAddToList::kNo);
   fitf1016->SetFillColor(19);
   fitf1016->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1016->SetLineColor(ci);
   fitf1016->SetLineWidth(3);
   fitf1016->SetChisquare(53.22238);
   fitf1016->SetNDF(4);
   fitf1016->GetXaxis()->SetLabelFont(42);
   fitf1016->GetXaxis()->SetLabelOffset(0.015);
   fitf1016->GetXaxis()->SetLabelSize(0.05);
   fitf1016->GetXaxis()->SetTitleSize(0.05);
   fitf1016->GetXaxis()->SetTitleOffset(1);
   fitf1016->GetYaxis()->SetLabelFont(42);
   fitf1016->GetYaxis()->SetLabelOffset(0.015);
   fitf1016->GetYaxis()->SetLabelSize(0.05);
   fitf1016->GetYaxis()->SetTitleSize(0.05);
   fitf1016->GetYaxis()->SetTickLength(0.02);
   fitf1016->GetYaxis()->SetTitleOffset(1);
   fitf1016->SetParameter(0,2.656241);
   fitf1016->SetParError(0,0.04522203);
   fitf1016->SetParLimits(0,0,0);
   fitf1016->SetParameter(1,0.02311702);
   fitf1016->SetParError(1,0.0002543697);
   fitf1016->SetParLimits(1,0,0);
   fitf1016->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1016);
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
