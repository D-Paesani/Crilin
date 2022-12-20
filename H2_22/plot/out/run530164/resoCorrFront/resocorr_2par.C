#ifdef __CLING__
#pragma cling optimize(0)
#endif
void resocorr_2par()
{
//=========Macro generated from canvas: c_7/c_7
//=========  (Tue Dec 20 15:49:54 2022) by ROOT version 6.26/06
   TCanvas *c_7 = new TCanvas("c_7", "c_7",0,0,600,400);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_7->SetHighLightColor(2);
   c_7->Range(17.61747,0.001679601,331.0989,0.05488359);
   c_7->SetFillColor(0);
   c_7->SetBorderMode(0);
   c_7->SetBorderSize(2);
   c_7->SetTickx(1);
   c_7->SetTicky(1);
   c_7->SetFrameBorderMode(0);
   c_7->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1013[6] = {
   72.02349,
   113.1542,
   153.7091,
   194.9694,
   235.621,
   276.6353};
   Double_t Graph0_fy1013[6] = {
   0.04693496,
   0.03513401,
   0.03021817,
   0.0274386,
   0.02523956,
   0.02446605};
   Double_t Graph0_fex1013[6] = {
   0.1102177,
   0.09619089,
   0.09293387,
   0.1019641,
   0.1224485,
   0.1678579};
   Double_t Graph0_fey1013[6] = {
   0.0003239248,
   0.0002058605,
   0.000168516,
   0.0001654203,
   0.0001865824,
   0.0002502206};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1013,Graph0_fy1013,Graph0_fex1013,Graph0_fey1013);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01013 = new TH1F("Graph_Graph01013","run530164",100,51.42429,297.2921);
   Graph_Graph01013->SetMinimum(0.007);
   Graph_Graph01013->SetMaximum(0.04956319);
   Graph_Graph01013->SetDirectory(0);
   Graph_Graph01013->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01013->SetLineColor(ci);
   Graph_Graph01013->SetLineWidth(2);
   Graph_Graph01013->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01013->GetXaxis()->SetRange(0,101);
   Graph_Graph01013->GetXaxis()->SetLabelFont(42);
   Graph_Graph01013->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01013->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01013->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01013->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01013->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01013->GetYaxis()->SetLabelFont(42);
   Graph_Graph01013->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01013->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01013->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01013->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01013->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01013->GetZaxis()->SetLabelFont(42);
   Graph_Graph01013->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01013->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01013->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01013->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01013->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01013);
   
   
   TF1 *fitf1014 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",51.42429,297.2921, TF1::EAddToList::kNo);
   fitf1014->SetFillColor(19);
   fitf1014->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1014->SetLineColor(ci);
   fitf1014->SetLineWidth(3);
   fitf1014->SetChisquare(25.25041);
   fitf1014->SetNDF(4);
   fitf1014->GetXaxis()->SetLabelFont(42);
   fitf1014->GetXaxis()->SetLabelOffset(0.015);
   fitf1014->GetXaxis()->SetLabelSize(0.05);
   fitf1014->GetXaxis()->SetTitleSize(0.05);
   fitf1014->GetXaxis()->SetTitleOffset(1);
   fitf1014->GetYaxis()->SetLabelFont(42);
   fitf1014->GetYaxis()->SetLabelOffset(0.015);
   fitf1014->GetYaxis()->SetLabelSize(0.05);
   fitf1014->GetYaxis()->SetTitleSize(0.05);
   fitf1014->GetYaxis()->SetTickLength(0.02);
   fitf1014->GetYaxis()->SetTitleOffset(1);
   fitf1014->SetParameter(0,3.036485);
   fitf1014->SetParError(0,0.02559631);
   fitf1014->SetParLimits(0,0,0);
   fitf1014->SetParameter(1,0.0223033);
   fitf1014->SetParError(1,0.0001618832);
   fitf1014->SetParLimits(1,0,0);
   fitf1014->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1014);
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
   c_7->Modified();
   c_7->cd();
   c_7->SetSelected(c_7);
}
