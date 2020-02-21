#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int dp[101][100001];
// dp[i][j]:i種類目の品物から、重さがjを超えないように選んだ時の価値の総和の最大値

int main(){
  int n,w;
  // cin>>n>>w;
  // vector<int>ws(n),vs(n);
  // rep(i,n)cin>>ws[i];
  // rep(i,n)cin>>vs[i];
  n=3;w=7;
  vector<int>ws({3,4,2});
  vector<int>vs({4,5,3});

  rep(i,n){
    rep(j, w+1){
      for(int k=0; k*ws[i]<=j; k++){
        // i種類の品物しかないところからi+1種類の品物があるループについてdp配列を構築している。
        // iの段の情報しかない中でi+1段目のdpを構築しようとしているため計算量が上がる
        dp[i+1][j] = max(dp[i][j-k*ws[i]] + k*vs[i], dp[i+1][j]);
      }

      rep(i,n+1){
        rep(j,w+1)cout<<dp[i][j]<<' ';
        cout<<endl;
      }
      cout<<"-----------"<<endl;

    }
  }

  cout<<dp[n][w]<<endl;

  return 0;
}
