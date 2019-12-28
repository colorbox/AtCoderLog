#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,k;cin>>n>>k;
  vector<pair<double, double>> cases;
  rep(i,n){
    double w,p;cin>>w>>p;
    cases.emplace_back(w,p);
  }

  double l=0.0,r=100.0, m;
  rep(i,100){
    m=(l+r)/2;
    vector<double> ps;
    rep(j,n)ps.push_back(cases[j].first*(cases[j].second-m));
    sort(ps.rbegin(), ps.rend());
//cout<<ps[0]<<','<<ps[1]<<' '<<ps[2]<<endl;
//cout<<accumulate(ps.begin(), ps.begin()+k, 0.0)<<endl;
    if(accumulate(ps.begin(), ps.begin()+k, 0.0)>=0.)l=m;
    else r=m;
  }

  cout<<fixed<<setprecision(10)<<m<<endl;

  return 0;
}
