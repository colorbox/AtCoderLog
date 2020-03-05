#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

double dp[2][(1<<15)+1];

int main(){
  int m;cin>>m;
  double p;cin>>p;
  int x;cin>>x;

  int n = 1<<m;
  double *prv = dp[0];
  double *nex = dp[1];
  memset(prv, 0, sizeof(double)*(n+1));
  prv[n] = 1.0;

  rep(r, m){
    for(int i=0; i<=n; i++){
      int jub = min(i, n-i);
      cout<<jub<<endl;

      double t = 0.0;
      for(int j=0; j <= jub; j++){
        cout<<i<<' '<<j<<'|'<<prv[i+j]<<' '<<prv[i-j]<<'='<<p*prv[i+j] + (1-p)*prv[i-j]<<endl;
        t = max(t, p*prv[i+j] + (1-p)*prv[i-j]);
      }
      cout<<t<<endl;
      cout<<"-"<<endl;
      nex[i]=t;
    }
    rep(i, n+2)cout<<prv[i]<<' ';cout<<endl;  

    swap(prv, nex);
    cout<<"#######"<<endl;
  }

  rep(i, n+2)cout<<prv[i]<<' ';cout<<endl;  

  int i = (ll)x*n/1000000;
  cout<<prv[i]<<endl;

  return 0;
}

/*
3 0.75 600000
*/
