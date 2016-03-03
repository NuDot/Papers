{

  TCanvas *can=new TCanvas("can","canvas");

  TLine *line = new TLine();
  line->SetLineWidth(2);

  double ymax = .9;
  line->DrawLine(.1,ymax,.4,ymax);
  
  
  ymax = 1740./3648*.9+.1;
  line->DrawLine(.55,ymax,.85,ymax);
  ymax = 718./3648*.9+.1;
  line->DrawLine(.55,ymax,.85,ymax);
  ymax = .1;
  line->DrawLine(.55,ymax,.85,ymax);

  TArrow *arr = new TArrow();
  arr->SetLineWidth(2);
  arr->SetFillStyle(1001);
  arr->SetFillColor(kBlack);

  arr->DrawArrow(.41,.9,.54,.72,.02,"|>");

  arr->DrawArrow(.65,1740./3648*.9+.1,.65,718./3648*.9+.11,.015,"|>");
  arr->DrawArrow(.68,718./3648*.9+.1,.68,.11,.015,"|>");
  
  TLatex *tex = new TLatex();
  tex->SetTextFont(132);
  tex->SetTextSize(.05);
  tex->SetTextAlign(22);

  tex->DrawLatex(.25,.85,"^{10}C");
  tex->DrawLatex(.70,.05,"^{10}B");
  tex->DrawLatex(.58,.13,"3^{+}");
  tex->DrawLatex(.58,718./3648*.9+.13,"1^{+}");
  tex->DrawLatex(.58,1740./3648*.9+.13,"0^{+}");
  tex->DrawLatex(.12,.93,"0^{+}");

  tex->SetTextSize(.04);
  tex->DrawLatex(.25,.8,"Q(gs)=3648 keV");

  tex->SetTextAlign(12);
  tex->DrawLatex(.46,.86,"#beta^{+}: 100%");
  
  tex->DrawLatex(.86,718./3648*.9+.1,"718 keV");
  tex->DrawLatex(.86,1740./3648*.9+.1,"1740 keV");

  tex->DrawLatex(.66,.5*(1740+718)/3648*.9+.1,"1021 keV");
  tex->DrawLatex(.69,.5*718/3648*.9+.1,"718 keV");
  
  tex->SetTextAlign(32);
  tex->DrawLatex(.84,718./3648*.9+.12,"#tau #approx 1 ns");
  tex->DrawLatex(.84,1740./3648*.9+.125,"#tau #approx 7 fs");
  tex->DrawLatex(.39,.925,"#tau #approx 27.8 s");

  tex->DrawLatex(.54,1740./3648*.9+.1,"1.5%");
  tex->DrawLatex(.54,718./3648*.9+.1,"98.5%");

		   
}
  
  
