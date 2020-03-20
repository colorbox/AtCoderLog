#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000

using namespace std;

#define MAXN 16
int d[MAXN][MAXN];
int dp[1<<MAXN][MAXN];

int main(){
  int n,e;cin>>n>>e;
  rep(i, MAXN)rep(j, MAXN)d[i][j]=-1;
  rep(i, e){
    int s,t,dist;cin>>s>>t>>dist;
    d[s][t]=dist;
  }

  rep(i, 1<<MAXN)rep(j, MAXN)dp[i][j]=INF;
  // rep(i, n)dp[(1<<n)-1][i]=0;
  dp[(1<<n)-1][0]=0;

  for(int s=(1<<n)-2; s>=0; s--){
    rep(from, n)rep(to, n){
      // 頂点toに未到達 かつ fromからtoに行くパスが存在している
      if( !(s>>to & 1) && d[from][to]!=-1 ){
      // if( (s>>to & 1)==0 && d[from][to]!=-1 ){
        dp[s][from] = min( dp[s][from], dp[s | 1<<to][to] + d[from][to] );
      }
    }

    // rep(i, 1<<n){rep(j, n)cout<<dp[i][j]<<' ';cout<<endl;}cout<<endl;

  }

  cout<<(dp[0][0]==INF ? -1 :dp[0][0])<<endl;

  // rep(i, 1<<n){rep(j, n)cout<<dp[i][j]<<' ';cout<<endl;}cout<<endl;

  return 0;
}
