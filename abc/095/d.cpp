#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,c;cin>>n>>c;
  ll dists[n],cals[n];
  ll n_cals[n], r_cals[n], n_cal_uppers[n], r_cal_uppers[n];
  ll result=0;
  n_cal_uppers[0]=-1*(1LL<<50), r_cal_uppers[0]=-1*(1LL<<50);
  rep(i,n){
    cin>>dists[i]>>cals[i];
  }

  n_cals[0]=cals[0];
  r_cals[0]=cals[n-1];
  rep(i,n-1){
    n_cals[i+1]=n_cals[i]+cals[i+1];
    r_cals[i+1]=r_cals[i]+cals[n-1-(i+1)];
  }
  rep(i,n){
    n_cals[i]-=dists[i];
    r_cals[i]-=(c-dists[n-1-i]);
  }

  n_cal_uppers[0]=max(0LL, n_cals[0]);
  r_cal_uppers[0]=max(0LL, r_cals[0]);
  rep(i,n-1){
    n_cal_uppers[i+1]=max(n_cal_uppers[i], n_cals[i+1]);
    r_cal_uppers[i+1]=max(r_cal_uppers[i], r_cals[i+1]);
  }

  rep(i,n){
    ll current_cal = max(n_cals[i], r_cals[i]);
    result = max(result, current_cal);
  }

  rep(i,n-1){
    ll current_cal = n_cals[i]+r_cal_uppers[n-1-i-1]-dists[i];
    ll reverse_cal = r_cals[i]+n_cal_uppers[n-1-i-1]-(c-dists[n-1-i]);

    ll tmp_cal = max(current_cal, reverse_cal);
    result = max(result, tmp_cal);
  }

  cout<<result<<endl;

//  rep(i,n)cout<<n_cals[i]<<' ';
//cout<<endl;
//  rep(i,n)cout<<n_cal_uppers[i]<<' ';
//cout<<endl;

//  rep(i,n)cout<<r_cals[i]<<' ';
//cout<<endl;
//  rep(i,n)cout<<r_cal_uppers[i]<<' ';

  return 0;
}
