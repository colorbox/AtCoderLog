#include<bits/stdc++.h>
long long MOD = pow(10,9)+7;
using namespace std;

int main(){
  int n, k;
  cin >>n;
  cin >>k;

// cout<<n<<' '<<k<<endl;

  long long dp[k+1+1][n+1];
  for(int i=0;i<k+1+1;i++){
    for(int j=0;j<n+1;j++){
      dp[i][j]=0;
    }
    dp[i][0]=1;
  }

  // for(int i=0;i<k+1+1;i++){
  //   for(int j=0;j<n+1;j++){
  //     cout<<dp[i][j]<<' ';
  //   }
  //     cout<<endl;
  // }

  for(int i=0;i<k+1;i++){
    for(int j=1;j<=n;j++){
      if(i-1>=0){
        dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%MOD;
      }else{
        dp[i+1][j]=dp[i+1][j-1]%MOD;
      }

    }
  }

  // cout<<endl;
  // cout<<endl;

  // for(int i=0;i<k+1+1;i++){
  //   for(int j=0;j<n+1;j++){
  //     cout<<dp[i][j]<<' ';
  //   }
  //     cout<<endl;
  // }



  cout<<dp[k+1][n-1];

  return 0;
}
