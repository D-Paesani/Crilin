void reso_corr()
{
//=========Macro generated from canvas: c_35/c_35
//=========  (Wed Oct 12 14:37:10 2022) by ROOT version 6.24/06
   TCanvas *c_35 = new TCanvas("c_35", "c_35",0,0,600,450);
   gStyle->SetOptFit(1);
   c_35->SetHighLightColor(2);
   c_35->Range(17.61747,0.01605669,331.0989,0.05548978);
   c_35->SetFillColor(0);
   c_35->SetBorderMode(0);
   c_35->SetBorderSize(2);
   c_35->SetFrameBorderMode(0);
   c_35->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1037[6] = {
   72.02349,
   113.1542,
   153.7091,
   194.9694,
   235.621,
   276.6353};
   Double_t Graph0_fy1037[6] = {
   0.04893367,
   0.03805155,
   0.03298004,
   0.02979863,
   0.02742695,
   0.02664905};
   Double_t Graph0_fex1037[6] = {
   0.1102177,
   0.09619089,
   0.09293387,
   0.1019641,
   0.1224485,
   0.1678579};
   Double_t Graph0_fey1037[6] = {
   0.0003237445,
   0.0002215196,
   0.000184871,
   0.0001834637,
   0.0002108675,
   0.0002821946};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1037,Graph0_fy1037,Graph0_fex1037,Graph0_fey1037);
   gre->SetName("Graph0");
   gre->SetTitle("run530164");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01037 = new TH1F("Graph_Graph01037","run530164",100,51.42429,297.2921);
   Graph_Graph01037->SetMinimum(0.02);
   Graph_Graph01037->SetMaximum(0.05154647);
   Graph_Graph01037->SetDirectory(0);
   Graph_Graph01037->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01037->SetLineColor(ci);
   Graph_Graph01037->GetXaxis()->SetTitle("mean SiPM charge [pC]");
   Graph_Graph01037->GetXaxis()->SetRange(0,101);
   Graph_Graph01037->GetXaxis()->SetLabelFont(42);
   Graph_Graph01037->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01037->GetXaxis()->SetTitleFont(42);
   Graph_Graph01037->GetYaxis()->SetTitle("mean time cell resolution [ns]");
   Graph_Graph01037->GetYaxis()->SetLabelFont(42);
   Graph_Graph01037->GetYaxis()->SetTitleFont(42);
   Graph_Graph01037->GetZaxis()->SetLabelFont(42);
   Graph_Graph01037->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01037->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01037);
   
   
   TF1 *fitf1038 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1]/x + [2]*[2])",51.42429,297.2921, TF1::EAddToList::kNo);
   fitf1038->SetFillColor(19);
   fitf1038->SetFillStyle(0);
   fitf1038->SetLineColor(2);
   fitf1038->SetLineWidth(2);
   fitf1038->SetChisquare(4.239344);
   fitf1038->SetNDF(3);
   fitf1038->GetXaxis()->SetLabelFont(42);
   fitf1038->GetXaxis()->SetTitleOffset(1);
   fitf1038->GetXaxis()->SetTitleFont(42);
   fitf1038->GetYaxis()->SetLabelFont(42);
   fitf1038->GetYaxis()->SetTitleFont(42);
   fitf1038->SetParameter(0,2.032866);
   fitf1038->SetParError(0,0.1829889);
   fitf1038->SetParLimits(0,0,0);
   fitf1038->SetParameter(1,0.3062638);
   fitf1038->SetParError(1,0.01931697);
   fitf1038->SetParLimits(1,0,0);
   fitf1038->SetParameter(2,0.01723988);
   fitf1038->SetParError(2,0.001200593);
   fitf1038->SetParLimits(2,0,0);
   fitf1038->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1038);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 2.03287 #pm 0.182989 ");
   ptstats_LaTex = ptstats->AddText("b [ns#bulletpC^{0.5}] = 0.306264 #pm 0.019317 ");
   ptstats_LaTex = ptstats->AddText("c [ns]   = 0.0172399 #pm 0.00120059 ");
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
   c_35->Modified();
   c_35->cd();
   c_35->SetSelected(c_35);
}
