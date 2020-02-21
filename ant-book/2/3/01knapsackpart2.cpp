#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

ll dp[101][100*100+1];
// dp[i][j]:i番目の品物を使って価値jを達成できる最小の重さ

int main(){
  ll N,W;
  N=4;
  W=5;
  vector<ll> w({2, 1, 3, 2});
  vector<ll> v({3, 2, 4, 2});

  ll max_v = 0;
  rep(i,N)max_v = max(max_v, v[i]);

  fill(dp[0], dp[0]+101*10001, INF);
  dp[0][0]=0;

  rep(i, N){
    rep(j, max_v*N+1){
      if(j-v[i]>=0) dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
      else dp[i+1][j] = dp[i][j];
    }

    rep(i, N+1){
      rep(j, max_v*N+1)cout<<(dp[i][j]==INF ? 0 : dp[i][j])<<' ';
      cout<<endl;
    }
    cout<<"---"<<endl;

  }

  ll result = 0;
  rep(i, max_v*N+1)if(dp[N][i]<=W)result=i;

  cout<<result;

  return 0;
}

/*
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 1 2 0 3 0 0 0 0 0 0 0 0 0 0 0 
0 0 1 2 3 3 4 5 0 6 0 0 0 0 0 0 0 
0 0 1 2 3 3 4 5 6 6 0 8 0 0 0 0 0 
*/
