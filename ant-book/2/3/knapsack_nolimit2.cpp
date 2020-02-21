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
      if(j-ws[i]>=0){
        // i+1種類の品物を利用する段の中で比較を行っている
        // i+1の段はi種類の品物を利用する段との比較となる
        dp[i+1][j] = max(dp[i+1][j-ws[i]] + vs[i], dp[i][j]);
      }else{
        // i+1の品物を取得できない時は、前の段の価値をそのまま持ってくる
        dp[i+1][j] = dp[i][j];
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

/*
0 0 0 0 0 0 0 0 
0 0 0 4 4 4 8 8 
0 0 0 4 5 5 8 9 
0 0 3 4 6 7 9 10 
*/
