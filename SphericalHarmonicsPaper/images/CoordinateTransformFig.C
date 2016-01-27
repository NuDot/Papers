{
  // Where to place circle 1
  double x1=.4,y1=.5;
  // Where to place circle 2
  double x2=.5,y2=.4;
  // Circle radius
  double r=.3;
  // Angle of photon in circle 1
  double theta=-70;

  TCanvas *can=new TCanvas("can","",600,600);

  // Draw circle 1
  TArc circ1(x1,y1,r);
  circ1.SetLineColor(kBlack);
  circ1.SetLineWidth(2);
  circ1.SetFillStyle(0);
  circ1.Draw();

  // Draw circle 2
  TArc circ2(x2,y2,r);
  circ2.SetLineColor(kBlack);
  circ2.SetLineWidth(2);
  circ2.SetLineStyle(kDashed);
  circ2.SetFillStyle(0);
  circ2.Draw();

  // Mark the center of the cirles
  TMarker mark;
  mark.SetMarkerStyle(5);
  mark.SetMarkerSize(2);
  mark.DrawMarker(x2,y2);
  mark.SetMarkerStyle(20);
  mark.SetMarkerSize(1);
  mark.DrawMarker(x1,y1);

  // Arrow from center to center
  TArrow arr;
  arr.SetLineWidth(2);
  arr.SetFillColor(kBlack);
  arr.SetLineColor(kBlack);
  arr.DrawArrow(x1,y1,x2,y2,.02,"|>");

  // Arrow from circle 1 center to "PMT"
  theta*=TMath::Pi()/180;
  double xp=.98*r*TMath::Cos(theta)+x1;
  double yp=.98*r*TMath::Sin(theta)+y1;
  arr.DrawArrow(x1,y1,xp,yp,.01,"|>");
  // Arrow from circle 2 center to PMT
  arr.DrawArrow(x2,y2,xp,yp,.01,"|>");

  // Arrow from circle 2 center to ghost PMT
  double d=sqrt((x2-xp)**2+(y2-yp)**2);
  double xpp = r*(xp-x2)/d+x2;
  double ypp = r*(yp-y2)/d+y2;
  arr.SetLineStyle(kDashed);
  arr.DrawArrow(xp,yp,xpp,ypp,.01,"|>");
  
  // Draw all the text
  TLatex tex;
  tex.SetTextSize(.04);
  tex.SetTextFont(12);
  tex.SetTextAlign(22);

  tex.DrawLatex(x1-.02,y1+.02,"O");
  tex.DrawLatex(x2+.03,y2+.02,"O'");

  tex.DrawLatex(.5*(x1+x2)+.01,.5*(y1+y2)+.03,"#vec{r}_{#font[132]{vtx}}");
  tex.DrawLatex(.5*(x1+xp)-.03,.5*(y1+yp),"#vec{r}_{#font[132]{hit}}");
  tex.DrawLatex(.5*(x2+xp)+.03,.5*(y2+yp),"#vec{a}");
  tex.DrawLatex(.5*(xpp+xp)+.03,.5*(ypp+yp),"#vec{r}'_{#font[132]{hit}}");

}
