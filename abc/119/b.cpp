#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  double sum=0;
  rep(i,n){
    double x;
    string u;
    cin>>x>>u;
    if(u=="BTC"){
      sum+=380000.0*x;
    }else{
      sum+=x;
    }
  }

  cout<<fixed<<setprecision(6)<<sum;

  return 0;
}
