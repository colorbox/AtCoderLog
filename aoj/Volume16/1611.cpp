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

#define MAXN 301
int n;

vector<int> w(MAXN);
int dp[MAXN][MAXN];

bool isin(int i, int j){
  return 0<=i && j<n;
}

bool bashable(int i, int j){
  return abs(w[i]-w[j])<=1;
}

int solve(){
  rep(i, n-1)dp[i][i+1] = bashable(i, i+1) ? 2 : 0;
  for(int len=4; len<=n; len+=2){
    rep(from, n-len+1){
      int to = from+len-1;

      int inner = from+1<to-1 ? dp[from+1][to-1] : 0;
      if(inner==len-2 && bashable(from, to))inner += 2;
      dp[from][to] = inner;

      for(int m=from; m<=to;m++){
        dp[from][to] = max(dp[from][to], dp[from][m]+dp[m+1][to]);
      }
    }
  }

  if(n%2) return max(dp[0][n-2], dp[1][n-1]);
  else return dp[0][n-1];
}

int main(){
  while(cin>>n){
    if(!n) break;

    rep(i, MAXN)w[i]=0;
    rep(i, MAXN)rep(j, MAXN)dp[i][j]=0;
    rep(i, n)cin>>w[i];
    int result = solve();
    cout<<result<<endl;

// rep(i, n){rep(j, n)cout<<dp[i][j]<<' ';cout<<endl;}

  }

  return 0;
}
