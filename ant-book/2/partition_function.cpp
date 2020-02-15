#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define ll long long

#define MOD 1000000007

using namespace std;

int dp[100][100];
// dp[i][j]:jをi分割した時の分割数

int main(){
  int n,m;
  n=4,m=3;

  dp[0][0]=1;
  for(int i=1; i<=m; i++){
    rep(j, n+1){
      if(j-i>=0) dp[i][j] = dp[i][j-i] + dp[i-1][j];
      else dp[i][j] = dp[i-1][j];
    }
  }

  cout<<dp[m][n]<<endl;

  rep(i,n){
    rep(j,m+2)cout<<dp[i][j]<<' ';cout<<endl;
  }

  return 0;
}

/*
1 0 0 0 0 
1 1 1 1 1 
1 1 2 2 3 
1 1 2 3 4 
*/
