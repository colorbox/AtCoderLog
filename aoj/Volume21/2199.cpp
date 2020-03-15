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

#define MAXM 16

ll dp[2][256];

ll makein(ll n){
  if(n<0)return 0;
  if(n>255)return 255;
  return n;
}

void solve(ll n, ll m){
  ll *now=dp[0];
  ll *nex=dp[1];
  
  rep(i, 256)nex[i]=now[i]=INF;
  now[128]=0;

  vector<ll> c(m);
  rep(i, m)cin>>c[i];

  vector<ll> x(n);
  rep(i, n)cin>>x[i];

  rep(i, n){
    rep(i, 256)nex[i]=INF;

    rep(from, 256)for(auto code: c){
      ll coded = makein(from+code);
      ll sq = (coded - x[i])*(coded - x[i]);
      nex[coded]=min(nex[coded],now[from]+sq);
    }
    swap(nex, now);
  }
  ll result = INF;
  rep(i, 256)result = min(result, now[i]);
  cout<<result<<endl;
}

int main(){
  while(true){
    ll n,m;cin>>n>>m;
    if(n==0)break;
    solve(n, m);
  }

  return 0;
}
