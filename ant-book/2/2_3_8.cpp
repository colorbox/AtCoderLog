//重複組合せ

#include<bits/stdc++.h>

using namespace std;

int n=3, m=3;
int a[] = {1,2,3};


int main(){
  int dp[n+1][m+1];
  memset(dp, 0, sizeof(dp));

  for(int i=0;i<=n;i++){
    dp[i][0]=1;
  }
  for(int i=0;i<n;i++){
    for(int j=1; j<=m;j++){
      if (j-1-a[i] >= 0){
        dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]];
      }else{
        dp[i+1][j] = dp[i+1][j-1] + dp[i][j];
      }
    }

    for(int i=0;i<=n;i++){
      for(int j=0; j<=m;j++){
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }

  cout << dp[n][m] << endl;

}
