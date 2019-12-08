#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,c;cin>>n>>c;
  ll dists[n], r_dists[n], cals[n], r_cals[n];
  rep(i,n){
    cin>>dists[i]>>cals[i];
    r_cals[n-1-i]=cals[i];
  }
  rep(i,n)r_dists[i]=c-dists[n-1-i];

  rep(i,n-1){
    cals[i+1]=cals[i+1]+cals[i];
    r_cals[i+1]=r_cals[i+1]+r_cals[i];
  }
  rep(i,n){
    cals[i]-=dists[i];
    r_cals[i]-=r_dists[i];
  }
  rep(i,n-1){
    cals[i+1]=max(cals[i], cals[i+1]);
    r_cals[i+1]=max(r_cals[i], r_cals[i+1]);
  }

  ll result=0;
  result = max(result, cals[n-1]);
  result = max(result, r_cals[n-1]);
  rep(i,n-1){
    result = max(result, cals[i]);
    result = max(result, cals[i]+r_cals[n-2-i]-dists[i]);
    result = max(result, r_cals[i]);
    result = max(result, r_cals[i]+cals[n-2-i]-r_dists[i]);
  }

  cout<<result<<endl;

//rep(i,n)cout<<cals[i]<<' ';cout<<endl;
//rep(i,n)cout<<r_cals[i]<<' ';cout<<endl;

  return 0;
}
