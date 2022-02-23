double logn2(double x, double eta, double sigma, double Epeak, double norm) {

  Double_t Aterm;
  Double_t logterms0,s0;
  Double_t logn,logterm;
  Double_t expterm;
  Double_t pigreco=3.14159265;
  

  ////////////////////////////// results from fit 
  //Double_t eta = -03914;
  //Double_t sigma = 0.0004587;
  //Double_t Epeak = 0.0007011;
  //Double_t norm = 0.1997;
  /////////////////////////////////////////////
  
  logterms0 = eta*2.35/2+sqrt(1+pow((eta*2.35/2),2));
  s0 = (2/2.35)*log(logterms0);

  Aterm = eta/(sqrt(2*pigreco)*sigma*s0);

  logterm = 1-(eta/sigma)*(x-Epeak);  

  
  if(logterm<0){
    logterm = 0.0001;
  }
  expterm = log(logterm)/s0;
  expterm = -0.5*pow(expterm,2);

  logn = norm*Aterm *exp(expterm);      
  return logn;

}


Double_t logn(Double_t *x, Double_t *par){
  Double_t Epeak, sigma, eta, norm;
  Double_t Aterm;
  Double_t logterms0,s0;
  Double_t logn,logterm;
  Double_t expterm;
  Double_t pigreco=3.14159265;
      
  eta = par[0];
  sigma = par[1];
  Epeak = par[2];
  norm = par[3];
      
      
  ////////////////////////////// results from fit 
  //Double_t eta = -03914;
  //Double_t sigma = 0.0004587;
  //Double_t Epeak = 0.0007011;
  //Double_t norm = 0.1997;
  /////////////////////////////////////////////
      
  logterms0 = eta*2.35/2+sqrt(1+pow((eta*2.35/2),2));
  s0 = (2/2.35)*log(logterms0);
    
  Aterm = eta/(sqrt(2*pigreco)*sigma*s0);

  logterm = 1-(eta/sigma)*(x[0]-Epeak);  

      
  if(logterm<0){
    logterm = 0.0001;
  }
  expterm = log(logterm)/s0;
  expterm = -0.5*pow(expterm,2);

  logn = norm*Aterm *exp(expterm);      
  return logn;
}  // fine function


Double_t logn3(Double_t *x, Double_t *par){
  Double_t Epeak, sigma, eta, norm, shift, fraction;
  Double_t Aterm;
  Double_t logterms0,s0;
  Double_t logn,logterm;
  Double_t expterm;
  Double_t pigreco=3.14159265;
  Double_t logn_shifted;
  Double_t const_fraction;
      
  eta = par[0];
  sigma = par[1];
  Epeak = par[2];
  norm = par[3];
  shift = par[4];
  fraction = par[5];
      
  ////////////////////////////// results from fit 
  //Double_t eta = -03914;
  //Double_t sigma = 0.0004587;
  //Double_t Epeak = 0.0007011;
  //Double_t norm = 0.1997;
  /////////////////////////////////////////////
      
  logterms0 = eta*2.35/2+sqrt(1+pow((eta*2.35/2),2));
  s0 = (2/2.35)*log(logterms0);
    
  Aterm = eta/(sqrt(2*pigreco)*sigma*s0);

  logterm = 1-(eta/sigma)*(x[0]-Epeak);  

      
  if(logterm<0){
    logterm = 0.0001;
  }
  expterm = log(logterm)/s0;
  expterm = -0.5*pow(expterm,2);

  logn = norm*Aterm *exp(expterm);


  Epeak += shift;

  logterms0 = eta*2.35/2+sqrt(1+pow((eta*2.35/2),2));
  s0 = (2/2.35)*log(logterms0);
    
  Aterm = eta/(sqrt(2*pigreco)*sigma*s0);

  logterm = 1-(eta/sigma)*(x[0]-Epeak);  

      
  if(logterm<0){
    logterm = 0.0001;
  }
  expterm = log(logterm)/s0;
  expterm = -0.5*pow(expterm,2);

  logn_shifted = norm*Aterm *exp(expterm);
  const_fraction=logn-fraction*logn_shifted;
      
  return const_fraction;
} 


Double_t dlogn(Double_t *x, Double_t *par){
  Double_t Epeak0, Epeak1, sigma, eta, norm0, norm1;
  Double_t Aterm;
  Double_t logterms0,s0;
  Double_t logn,logterm0, logterm1;
  Double_t expterm0, expterm1;
  Double_t pigreco=3.14159265;
      
  eta    = par[0];
  sigma  = par[1];
  Epeak0 = par[2];
  Epeak1 = par[3];
  norm0  = par[4];
  norm1  = par[5];
      
      
  ////////////////////////////// results from fit 
  //Double_t eta = -03914;
  //Double_t sigma = 0.0004587;
  //Double_t Epeak = 0.0007011;
  //Double_t norm = 0.1997;
  /////////////////////////////////////////////
      
  logterms0 = eta*2.35/2+sqrt(1+pow((eta*2.35/2),2));
  s0 = (2/2.35)*log(logterms0);
    
  Aterm = eta/(sqrt(2*pigreco)*sigma*s0);

  logterm0 = 1-(eta/sigma)*(x[0]-Epeak0);  
  logterm1 = 1-(eta/sigma)*(x[0]-Epeak1);  
      
  if(logterm0<0){
    logterm0 = 0.0001;
  }
  if(logterm1<0){
    logterm1 = 0.0001;
  }
  expterm0 = log(logterm0)/s0;
  expterm0 = -0.5*pow(expterm0,2);

  expterm1 = log(logterm1)/s0;
  expterm1 = -0.5*pow(expterm1,2);

  logn = Aterm *( norm0*exp(expterm0) + norm1*exp(expterm1));      

  return logn;
} 
