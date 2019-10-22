// from https://atcoder.jp/contests/joi2009yo/submissions/7979897

#include <bits/stdc++.h>

using namespace std;

int n, m, s, MOD=100000;
main(){
    // n=3;
    // m=9;
    // s=45;
  cin >> n >>m >>s;
  int dp[n*n+1][s+1];
  memset(dp, 0, sizeof(dp));
  dp[0][0]=1;

  for(int i=1 ; i<=m ; i++){
    for(int j=n*n ; j>0 ; j--){
      for(int k=1 ; k<=s ; k++){
        if(k-i<0){continue;}

        dp[j][k] += dp[j-1][k-i];
        dp[j][k] %= MOD;
      }
    }

    // for(int i=0;i<n*n;i++){
    //     for(int j=0;j<s;j++){
    //       printf(" %2d", dp[i][j]);

    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<endl;

  }
  cout << dp[n*n][s]<<endl;
}
