void reso_corr()
{
//=========Macro generated from canvas: c_5/c_5
//=========  (Wed Oct 12 14:41:30 2022) by ROOT version 6.24/06
   TCanvas *c_5 = new TCanvas("c_5", "c_5",0,0,600,450);
   gStyle->SetOptFit(1);
   c_5->SetHighLightColor(2);
   c_5->Range(17.61747,0.01605712,331.0989,0.05548595);
   c_5->SetFillColor(0);
   c_5->SetBorderMode(0);
   c_5->SetBorderSize(2);
   c_5->SetFrameBorderMode(0);
   c_5->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1046[6] = {
   72.02349,
   113.1542,
   153.7091,
   194.9694,
   235.621,
   276.6353};
   Double_t Graph0_fy1046[6] = {
   0.04887173,
   0.03767071,
   0.0327286,
   0.02933585,
   0.02681088,
   0.02625473};
   Double_t Graph0_fex1046[6] = {
   0.1102177,
   0.09619089,
   0.09293387,
   0.1019641,
   0.1224485,
   0.1678579};
   Double_t Graph0_fey1046[6] = {
   0.0003460779,
   0.0002226714,
   0.0001880024,
   0.0001780806,
   0.0002052942,
   0.0002895132};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1046,Graph0_fy1046,Graph0_fex1046,Graph0_fey1046);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01046 = new TH1F("Graph_Graph01046","run530164",100,51.42429,297.2921);
   Graph_Graph01046->SetMinimum(0.02);
   Graph_Graph01046->SetMaximum(0.05154307);
   Graph_Graph01046->SetDirectory(0);
   Graph_Graph01046->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01046->SetLineColor(ci);
   Graph_Graph01046->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01046->GetXaxis()->SetRange(0,101);
   Graph_Graph01046->GetXaxis()->SetLabelFont(42);
   Graph_Graph01046->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01046->GetXaxis()->SetTitleFont(42);
   Graph_Graph01046->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01046->GetYaxis()->SetLabelFont(42);
   Graph_Graph01046->GetYaxis()->SetTitleFont(42);
   Graph_Graph01046->GetZaxis()->SetLabelFont(42);
   Graph_Graph01046->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01046->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01046);
   
   
   TF1 *fitf1047 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",51.42429,297.2921, TF1::EAddToList::kNo);
   fitf1047->SetFillColor(19);
   fitf1047->SetFillStyle(0);
   fitf1047->SetLineColor(2);
   fitf1047->SetLineWidth(2);
   fitf1047->SetChisquare(9.193549);
   fitf1047->SetNDF(3);
   fitf1047->GetXaxis()->SetLabelFont(42);
   fitf1047->GetXaxis()->SetTitleOffset(1);
   fitf1047->GetXaxis()->SetTitleFont(42);
   fitf1047->GetYaxis()->SetLabelFont(42);
   fitf1047->GetYaxis()->SetTitleFont(42);
   fitf1047->SetParameter(0,2.05045);
   fitf1047->SetParError(0,0.18635);
   fitf1047->SetParLimits(0,0,0);
   fitf1047->SetParameter(1,0.3072118);
   fitf1047->SetParError(1,0.0195122);
   fitf1047->SetParLimits(1,0,0);
   fitf1047->SetParameter(2,0.0162981);
   fitf1047->SetParError(2,0.001275697);
   fitf1047->SetParLimits(2,0,0);
   fitf1047->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1047);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 2.05045 #pm 0.18635 ");
   ptstats_LaTex = ptstats->AddText("b [ns#bulletpC^{0.5}] = 0.307212 #pm 0.0195122 ");
   ptstats_LaTex = ptstats->AddText("c [ns]   = 0.0162981 #pm 0.0012757 ");
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
