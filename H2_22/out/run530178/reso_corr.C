void reso_corr()
{
//=========Macro generated from canvas: c_5/c_5
//=========  (Wed Oct 12 17:16:43 2022) by ROOT version 6.24/06
   TCanvas *c_5 = new TCanvas("c_5", "c_5",0,0,600,450);
   gStyle->SetOptFit(1);
   c_5->SetHighLightColor(2);
   c_5->Range(16.34721,0.001860151,332.1538,0.08325863);
   c_5->SetFillColor(0);
   c_5->SetBorderMode(0);
   c_5->SetBorderSize(2);
   c_5->SetFrameBorderMode(0);
   c_5->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1022[6] = {
   71.37773,
   113.6012,
   154.6275,
   196.0011,
   236.4267,
   277.1248};
   Double_t Graph0_fy1022[6] = {
   0.06901215,
   0.04821484,
   0.04237135,
   0.03461149,
   0.03264784,
   0.03036197};
   Double_t Graph0_fex1022[6] = {
   0.3319877,
   0.2768332,
   0.2502175,
   0.2467299,
   0.2614082,
   0.3304662};
   Double_t Graph0_fey1022[6] = {
   0.001967237,
   0.001062333,
   0.0008038069,
   0.0005820698,
   0.0006383638,
   0.0007765887};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1022,Graph0_fy1022,Graph0_fex1022,Graph0_fey1022);
   gre->SetName("Graph0");
   gre->SetTitle("run530178");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01022 = new TH1F("Graph_Graph01022","run530178",100,50.40479,298.0962);
   Graph_Graph01022->SetMinimum(0.01);
   Graph_Graph01022->SetMaximum(0.07511878);
   Graph_Graph01022->SetDirectory(0);
   Graph_Graph01022->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01022->SetLineColor(ci);
   Graph_Graph01022->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01022->GetXaxis()->SetRange(0,101);
   Graph_Graph01022->GetXaxis()->SetLabelFont(42);
   Graph_Graph01022->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01022->GetXaxis()->SetTitleFont(42);
   Graph_Graph01022->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01022->GetYaxis()->SetLabelFont(42);
   Graph_Graph01022->GetYaxis()->SetTitleFont(42);
   Graph_Graph01022->GetZaxis()->SetLabelFont(42);
   Graph_Graph01022->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01022->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01022);
   
   
   TF1 *fitf1023 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",50.40479,298.0962, TF1::EAddToList::kNo);
   fitf1023->SetFillColor(19);
   fitf1023->SetFillStyle(0);
   fitf1023->SetLineColor(2);
   fitf1023->SetLineWidth(2);
   fitf1023->SetChisquare(8.823096);
   fitf1023->SetNDF(3);
   fitf1023->GetXaxis()->SetLabelFont(42);
   fitf1023->GetXaxis()->SetTitleOffset(1);
   fitf1023->GetXaxis()->SetTitleFont(42);
   fitf1023->GetYaxis()->SetLabelFont(42);
   fitf1023->GetYaxis()->SetTitleFont(42);
   fitf1023->SetParameter(0,3.78453);
   fitf1023->SetParError(0,0.5841538);
   fitf1023->SetParLimits(0,0,0);
   fitf1023->SetParameter(1,0.3379148);
   fitf1023->SetParError(1,0.09135117);
   fitf1023->SetParLimits(1,0,0);
   fitf1023->SetParameter(2,0.01762413);
   fitf1023->SetParError(2,0.005506108);
   fitf1023->SetParLimits(2,0,0);
   fitf1023->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1023);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 3.78453 #pm 0.584154 ");
   ptstats_LaTex = ptstats->AddText("b [ns#bulletpC^{0.5}] = 0.337915 #pm 0.0913512 ");
   ptstats_LaTex = ptstats->AddText("c [ns]   = 0.0176241 #pm 0.00550611 ");
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
   TText *pt_LaTex = pt->AddText("run530178");
   pt->Draw();
   c_5->Modified();
   c_5->cd();
   c_5->SetSelected(c_5);
}
