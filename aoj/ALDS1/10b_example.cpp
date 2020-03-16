// from: https://muttan1203.hatenablog.com/entry/ALDS_1_10_B
#include <iostream>

using namespace std;

#define rep(i,n) REP(i,0,n)
#define REP(i,a,n) for(int i = a ; i < (int)n ; i++)

#define N 101

int dp[N+1][N+1], p[N+1];

int main(){
  int n;
    
  cin >> n;
  REP(i, 1, n+1){
    cin >> p[i-1] >> p[i];
  }

  for(int l=2; l<n+1; l++){           // 対象とする行列の数
    for(int i=1; i<n-l+2; i++){
      int j = i + l - 1;
      dp[i][j] = (1 << 20); // dp[i][j] := [Mi, Mj]の最小回数
      for(int k = i ; k < j ; k++){

        cout<<i<<' '<<k<<' '<<j<<'|'<<dp[i][k]<<' '<<dp[k+1][j]<<' '<<p[i-1]*p[j]*p[k]<<endl;

      	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]);
      }
      rep(i, n+1){rep(j, n+1)cout<<dp[i][j]<<' ';cout<<endl;}
      cout<<endl;
      cout<<endl;
      
    }
  }

  cout << dp[1][n] << endl;

  rep(i, n+1){rep(j, n+1)cout<<dp[i][j]<<' ';cout<<endl;}
  cout<<endl;

  return 0;
}

/*
1 1 3|0 2625 5250
1 2 3|15750 0 2250

0 0     0    0   0    0    0 
0 0 15750 7875   0    0    0 
0 0     0 2625   0    0    0 
0 0     0    0 750    0    0 
0 0     0    0   0 1000    0 
0 0     0    0   0    0 5000 
0 0 0 0 0 0 0 
*/

/*
  for(int l=2; l<=n+1; l++){
    for(int i=0; i<n-l+2; i++){
      int j = i + l;
      dp[i][j] = (1 << 20); // dp[i][j] := [Mi, Mj]の最小回数
      for(int k = i+1 ; k < j ; k++){

        cout<<i<<' '<<k<<' '<<j<<'|'<<dp[i][k]<<' '<<dp[k][j]<<' '<<p[i]*p[j]*p[k]<<endl;

      	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + p[i] * p[k] * p[j]);
      }
      rep(i, n+1){rep(j, n+1)cout<<dp[i][j]<<' ';cout<<endl;}
      cout<<endl;
      cout<<endl;
      
    }
  }
*/
