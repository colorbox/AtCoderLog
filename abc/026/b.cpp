#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;
  cin>>n;
  double r=0.0, w=0.0;
  vector<double> rr;
  rep(i,n){
    double c;
    cin>>c;
    rr.push_back(c);
  }
  
  sort(rr.rbegin(), rr.rend());
  
  double result = 0.0;
  rep(i,n){
    double c = rr[i];
    double s = pow(c,2)*M_PI;
    if(i%2==0){
      result += s;
    }else{
      result -= s;
    }    
  }
  cout<<fixed<<setprecision(10)<<result<<endl;
  
  return 0;
}
