#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define ll long long

#define MOD 1000000007

using namespace std;

int dp[1001][1001];

int main(){
  int n,m;
  n=3;
  m=3;
  vector<int> a({1,2,3});

  rep(i, n+1) dp[i][0]=1;
  // 0個選ぶのは常に無を選ぶという一種類しかない

  rep(i,n){
    for(int j=1; j<m+1; j++){
      if(j>=a[i]+1) dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]];
      else dp[i+1][j] = dp[i+1][j-1] + dp[i][j];
    }

    rep(i,n+1){
      rep(j, m+1)cout<<dp[i][j]<<' ';cout<<endl;
    }
    cout<<"---"<<endl;
  }

  cout<<dp[n][m];

  return 0;
}

/*
1 0 0 0 
1 1 0 0 
1 0 0 0 
1 0 0 0 
---
1 0 0 0 
1 1 0 0 
1 2 2 1 
1 0 0 0 
---
1 0 0 0 
1 1 0 0 
1 2 2 1 
1 3 5 6 
*/
