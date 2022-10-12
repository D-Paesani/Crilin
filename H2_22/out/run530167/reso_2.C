void reso_2()
{
//=========Macro generated from canvas: c_1/c_1
//=========  (Wed Oct 12 11:28:37 2022) by ROOT version 6.24/06
   TCanvas *c_1 = new TCanvas("c_1", "c_1",0,0,600,450);
   gStyle->SetOptFit(1);
   c_1->SetHighLightColor(2);
   c_1->Range(18.90836,-0.001347168,328.7296,0.03212451);
   c_1->SetFillColor(0);
   c_1->SetBorderMode(0);
   c_1->SetBorderSize(2);
   c_1->SetFrameBorderMode(0);
   c_1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1022[6] = {
   72.69547,
   112.9555,
   153.0001,
   193.8512,
   234.1903,
   274.7239};
   Double_t Graph0_fy1022[6] = {
   0.02682745,
   0.01902874,
   0.014868,
   0.01268887,
   0.01110502,
   0.01018202};
   Double_t Graph0_fex1022[6] = {
   0.1252521,
   0.108464,
   0.1160687,
   0.1455879,
   0.2104007,
   0.3439065};
   Double_t Graph0_fey1022[6] = {
   0.0002360915,
   0.0001456229,
   0.0001187636,
   0.0001256567,
   0.0001732143,
   0.0002565158};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1022,Graph0_fy1022,Graph0_fex1022,Graph0_fey1022);
   gre->SetName("Graph0");
   gre->SetTitle("run530167");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   
   TH1F *Graph_Graph01022 = new TH1F("Graph_Graph01022","run530167",100,52.32046,295.3175);
   Graph_Graph01022->SetMinimum(0.002);
   Graph_Graph01022->SetMaximum(0.02877734);
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
   
   
   TF1 *fitf1023 = new TF1("fitf","sqrt([0]*[0]/(x*x) + [1]*[1])",52.32046,295.3175, TF1::EAddToList::kNo);
   fitf1023->SetFillColor(19);
   fitf1023->SetFillStyle(0);
   fitf1023->SetLineColor(2);
   fitf1023->SetLineWidth(2);
   fitf1023->SetChisquare(17.3308);
   fitf1023->SetNDF(4);
   fitf1023->GetXaxis()->SetLabelFont(42);
   fitf1023->GetXaxis()->SetTitleOffset(1);
   fitf1023->GetXaxis()->SetTitleFont(42);
   fitf1023->GetYaxis()->SetLabelFont(42);
   fitf1023->GetYaxis()->SetTitleFont(42);
   fitf1023->SetParameter(0,1.912281);
   fitf1023->SetParError(0,0.01679948);
   fitf1023->SetParLimits(0,0,0);
   fitf1023->SetParameter(1,0.007885544);
   fitf1023->SetParError(1,0.0001853192);
   fitf1023->SetParLimits(1,0,0);
   fitf1023->SetParent(gre);
   gre->GetListOfFunctions()->Add(fitf1023);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.815,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("a [ns#bulletpC] = 1.91228 #pm 0.0167995 ");
   ptstats_LaTex = ptstats->AddText("b [ns]   = 0.00788554 #pm 0.000185319 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(11);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ap");
   TGaxis *gaxis = new TGaxis(60,0.006,290,0.006,148.8,719.2,510,"-");
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
   TText *pt_LaTex = pt->AddText("run530167");
   pt->Draw();
   c_1->Modified();
   c_1->cd();
   c_1->SetSelected(c_1);
}
