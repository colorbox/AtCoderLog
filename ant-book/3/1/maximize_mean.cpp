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
  ll n=3,k=2;
  vector<ll> w({2,5,2}), v({2,3,1});

  double minv = 0.0, maxv = (double)INF;
  while(maxv-minv>0.001){
    double mid = (minv+maxv)/2;
    vector<double> y;

    rep(i,n)y.push_back((double)v[i]-(double)mid*w[i]);
//    rep(i,n)cout<<v[i]<<' '<<mid<<' '<<w[i]<<endl;
    sort(y.rbegin(), y.rend());

    double sum = 0.0;
    rep(i,k)sum += y[i];
    // rep(i,n)cout<<y[i]<<' ';cout<<endl;

    if(sum>0.0)minv=mid;
    else maxv=mid;
  cout<<sum<<' '<<mid<<endl;
  }

  cout<<minv<<' '<<maxv<<endl;

  return 0;
}
