#ifdef __CLING__
#pragma cling optimize(0)
#endif
void reso_corr()
{
//=========Macro generated from canvas: c_13/c_13
//=========  (Tue Dec 20 10:52:41 2022) by ROOT version 6.26/06
   TCanvas *c_13 = new TCanvas("c_13", "c_13",0,0,600,450);
   gStyle->SetOptFit(1);
   gStyle->SetOptTitle(0);
   c_13->SetHighLightColor(2);
   c_13->Range(17.33989,0.001665704,331.4606,0.08500866);
   c_13->SetFillColor(0);
   c_13->SetBorderMode(0);
   c_13->SetBorderSize(2);
   c_13->SetTickx(1);
   c_13->SetTicky(1);
   c_13->SetFrameBorderMode(0);
   c_13->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1016[6] = {
   71.91881,
   113.8038,
   154.5941,
   195.6856,
   236.4399,
   276.8942};
   Double_t Graph0_fy1016[6] = {
   0.07215939,
   0.05226419,
   0.04616033,
   0.04241582,
   0.03902916,
   0.0365251};
   Double_t Graph0_fex1016[6] = {
   0.1723914,
   0.1388822,
   0.1209727,
   0.1189875,
   0.1300765,
   0.1598944};
   Double_t Graph0_fey1016[6] = {
   0.0008326632,
   0.0004551543,
   0.0003495059,
   0.0003112068,
   0.0003060492,
   0.0003561264};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1016,Graph0_fy1016,Graph0_fex1016,Graph0_fey1016);
   gre->SetName("Graph0");
   gre->SetTitle("run530178");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01016 = new TH1F("Graph_Graph01016","run530178",100,51.21565,297.5848);
   Graph_Graph01016->SetMinimum(0.01);
   Graph_Graph01016->SetMaximum(0.07667436);
   Graph_Graph01016->SetDirectory(0);
   Graph_Graph01016->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000cc");
   Graph_Graph01016->SetLineColor(ci);
   Graph_Graph01016->SetLineWidth(2);
   Graph_Graph01016->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01016->GetXaxis()->SetRange(0,101);
   Graph_Graph01016->GetXaxis()->SetLabelFont(42);
   Graph_Graph01016->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01016->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01016->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01016->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01016->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01016->GetYaxis()->SetLabelFont(42);
   Graph_Graph01016->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01016->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01016->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01016->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01016->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01016->GetZaxis()->SetLabelFont(42);
   Graph_Graph01016->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01016->GetZaxis()->SetLabelSize(0.03);
   Graph_Graph01016->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01016->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01016->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01016);
   
   
   TF1 *fitf1017 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",51.21565,297.5848, TF1::EAddToList::kNo);
   fitf1017->SetFillColor(19);
   fitf1017->SetFillStyle(0);

   ci = TColor::GetColor("#cc0000");
   fitf1017->SetLineColor(ci);
   fitf1017->SetLineWidth(3);
   fitf1017->SetChisquare(34.45272);
   fitf1017->SetNDF(4);
   fitf1017->GetXaxis()->SetLabelFont(42);
   fitf1017->GetXaxis()->SetLabelOffset(0.015);
   fitf1017->GetXaxis()->SetLabelSize(0.05);
   fitf1017->GetXaxis()->SetTitleSize(0.05);
   fitf1017->GetXaxis()->SetTitleOffset(1);
   fitf1017->GetYaxis()->SetLabelFont(42);
   fitf1017->GetYaxis()->SetLabelOffset(0.015);
   fitf1017->GetYaxis()->SetLabelSize(0.05);
   fitf1017->GetYaxis()->SetTitleSize(0.05);
   fitf1017->GetYaxis()->SetTickLength(0.02);
   fitf1017->GetYaxis()->SetTitleOffset(1);
   fitf1017->SetParameter(0,4.646605);
   fitf1017->SetParError(0,0.0578422);
   fitf1017->SetParLimits(0,0,0);
   fitf1017->SetParameter(1,0.03391021);
   fitf1017->SetParError(1,0.0002964948);
   fitf1017->SetParLimits(1,0,0);
   fitf1017->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1017);
   
   TPaveStats *ptstats = new TPaveStats(0.49,0.73,0.85,0.85,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 4.64661 #pm 0.0578422 ");
   ptstats_LaTex = ptstats->AddText("b [ns]   = 0.0339102 #pm 0.000296495 ");
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
   c_13->Modified();
   c_13->cd();
   c_13->SetSelected(c_13);
}
