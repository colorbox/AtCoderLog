#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n = 4, k=11;
  vector<double> ls({8.02, 7.43, 4.57, 5.39});
  double l = 0.0, r = INF, m;

  while(r-l > 0.001){
    double m = (r+l)/2;
    ll count = 0;
    rep(i, n) count += (ll)ls[i]/m;
    if(count>=k) l=m;
    else r=m;
    cout<<count<<' '<<m<<endl;
  }

  cout<<fixed<<setprecision(12)<<l;

  return 0;
}
