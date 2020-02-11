#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int dp[11][11];
// dp[i][j]:i個までの品物を使って、重さjで実現可能な最大価値

int main(){
  int n, w;
  // vector<int>ws(n),vs(n);
  n = 4;w=5;
  vector<int> ws({2,1,3,2});
  vector<int> vs({3,2,4,2});


  // cin>>n>>w;
  // rep(i,n)cin>>ws[i];
  // rep(i,n)cin>>vs[i];

  for(int i=0; i<n; i++){
    rep(j,w+1){

      rep(i,n+1){
        rep(j,w+1)cout<<dp[i][j]<<' ';
        cout<<endl;
      }
      cout<<"-----------"<<endl;

      if(j-ws[i]>=0){
        dp[i+1][j] = max(dp[i][j], dp[i][j-ws[i]]+vs[i]);
      }else{
        dp[i+1][j] = max( dp[i][j], dp[i][j-1]);
      }
    }

    cout<<dp[n][w];
  }

  return 0;
}
