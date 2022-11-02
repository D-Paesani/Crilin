void reso_corr_2par()
{
//=========Macro generated from canvas: c_6/c_6
//=========  (Wed Oct 12 17:17:32 2022) by ROOT version 6.24/06
   TCanvas *c_6 = new TCanvas("c_6", "c_6",0,0,600,450);
   gStyle->SetOptFit(1);
   c_6->SetHighLightColor(2);
   c_6->Range(16.34721,0.001860151,332.1538,0.08325863);
   c_6->SetFillColor(0);
   c_6->SetBorderMode(0);
   c_6->SetBorderSize(2);
   c_6->SetFrameBorderMode(0);
   c_6->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1025[6] = {
   71.37773,
   113.6012,
   154.6275,
   196.0011,
   236.4267,
   277.1248};
   Double_t Graph0_fy1025[6] = {
   0.06901215,
   0.04821484,
   0.04237135,
   0.03461149,
   0.03264784,
   0.03036197};
   Double_t Graph0_fex1025[6] = {
   0.3319877,
   0.2768332,
   0.2502175,
   0.2467299,
   0.2614082,
   0.3304662};
   Double_t Graph0_fey1025[6] = {
   0.001967237,
   0.001062333,
   0.0008038069,
   0.0005820698,
   0.0006383638,
   0.0007765887};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1025,Graph0_fy1025,Graph0_fex1025,Graph0_fey1025);
   gre->SetName("Graph0");
   gre->SetTitle("run530178");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01025 = new TH1F("Graph_Graph01025","run530178",100,50.40479,298.0962);
   Graph_Graph01025->SetMinimum(0.01);
   Graph_Graph01025->SetMaximum(0.07511878);
   Graph_Graph01025->SetDirectory(0);
   Graph_Graph01025->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01025->SetLineColor(ci);
   Graph_Graph01025->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01025->GetXaxis()->SetRange(0,101);
   Graph_Graph01025->GetXaxis()->SetLabelFont(42);
   Graph_Graph01025->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01025->GetXaxis()->SetTitleFont(42);
   Graph_Graph01025->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01025->GetYaxis()->SetLabelFont(42);
   Graph_Graph01025->GetYaxis()->SetTitleFont(42);
   Graph_Graph01025->GetZaxis()->SetLabelFont(42);
   Graph_Graph01025->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01025->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01025);
   
   
   TF1 *fitf1026 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",50.40479,298.0962, TF1::EAddToList::kNo);
   fitf1026->SetFillColor(19);
   fitf1026->SetFillStyle(0);
   fitf1026->SetLineColor(2);
   fitf1026->SetLineWidth(2);
   fitf1026->SetChisquare(12.18611);
   fitf1026->SetNDF(4);
   fitf1026->GetXaxis()->SetLabelFont(42);
   fitf1026->GetXaxis()->SetTitleOffset(1);
   fitf1026->GetXaxis()->SetTitleFont(42);
   fitf1026->GetYaxis()->SetLabelFont(42);
   fitf1026->GetYaxis()->SetTitleFont(42);
   fitf1026->SetParameter(0,4.720411);
   fitf1026->SetParError(0,0.1208708);
   fitf1026->SetParLimits(0,0,0);
   fitf1026->SetParameter(1,0.02574213);
   fitf1026->SetParError(1,0.0007303808);
   fitf1026->SetParLimits(1,0,0);
   fitf1026->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1026);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.815,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 4.72041 #pm 0.120871 ");
   ptstats_LaTex = ptstats->AddText("b [ns]   = 0.0257421 #pm 0.000730381 ");
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
   c_6->Modified();
   c_6->cd();
   c_6->SetSelected(c_6);
}
