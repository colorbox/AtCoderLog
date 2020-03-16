#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000

using namespace std;

#define MAXN 101
int dp[MAXN][MAXN];

int main(){
  int n;cin>>n;
  vector<int> r(n),c(n), rc(n+1);
  rep(i, n){
    cin>>r[i]>>c[i];
    rc[i]=r[i];
  }
  rc[n]=c[n-1];

  rep(i, n+1)cout<<rc[i]<<' ';cout<<endl;
  rep(i, n)cout<<r[i]<<' ';cout<<endl;
  rep(i, n)cout<<c[i]<<' ';cout<<endl<<endl;

  // 行列数2について予め計算しておく
  // rep(i, n-1)dp[i][i+2]=rc[i]*rc[i+1]*rc[i+2];

  rep(i, n+1){rep(j, n+1)cout<<dp[i][j]<<' ';cout<<endl;}
  cout<<endl;

  // dp[i][j]:i~j番目までの

  // 計算対象となる行列の数
  for(int len=2; len<=n+1; len++){
    // 行列の個数が入る分だけ左端から全て計算する
    rep(i, n+1-len+1){
      int j=i+len;
      dp[i][j]=INF;
      // lenの中で最後に計算する場所についてループを回して全チェック
      // 両端を含む必要はないのでkはi+1で初期化し、i+len-1までのループにする。
      for(int k=i+1; k<j; k++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + rc[i]*rc[j]*rc[k]);
        cout<<i<<' '<<k<<' '<<j<<'|'<<dp[i][k]<<' '<<dp[k][j]<<' '<<rc[i]*rc[j]*rc[k]<<endl;
      }

      rep(i, n+1){rep(j, n+1)cout<<dp[i][j]<<' ';cout<<endl;}cout<<endl;

      cout<<endl;
    }
  }

  cout<<dp[0][n]<<endl;

  rep(i, n+1){rep(j, n+1)cout<<dp[i][j]<<' ';cout<<endl;}
  cout<<endl;

  return 0;
}

/*
0 1 3|0 2625 5250
0 2 3|15750 0 2250

0 0 15750 7875   0    0    0 
0 0     0 2625   0    0    0 
0 0     0    0 750    0    0 
0 0     0    0   0 1000    0 
0 0     0    0   0    0 5000 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 

*/

/*
6
30 35
35 15
15 5
5 10
10 20
20 25
*/
