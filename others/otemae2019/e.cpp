#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long
#define MOD 1000000007

using namespace std;

int dp[1001][1001][15];

int main(){
  int n, m;cin>>n>>m;
  vector<int> s(m+1, -1);
  rep(i, m){
    string t;cin>>t;
    int tt = 0;
    if(t=="Fizz")s[i]=0;
    if(t=="Buzz")s[i]=1;
    if(t=="FizzBuzz")s[i]=2;
  }

  dp[0][0][0]=1;

  rep(i, n){
    rep(j, m+1){
      rep(k, 15){
        for(int a = (i==0 ? 1 : 0); a<=9; a++){
          int to = (k*10+a)%15;
          // 発言がある時
          if( to == 0){
            if(s[j]==2){
              dp[i+1][j+1][to]+=dp[i][j][k];
              dp[i+1][j+1][to] %= MOD;
            }
          } else if(to%3==0){
            if(s[j]==0){
              dp[i+1][j+1][to]+=dp[i][j][k];
              dp[i+1][j+1][to] %= MOD;
            }
          } else if(to%5==0) {
            if(s[j]==1){
              dp[i+1][j+1][to]+=dp[i][j][k];
              dp[i+1][j+1][to] %= MOD;
            }
          } else {
            // 発言がない時
            dp[i+1][j][to] += dp[i][j][k];
            dp[i+1][j][to] %= MOD;
          }
        }
      }
    }
  }

  ll result = 0;
  rep(i, 15){
    result += dp[n][m][i];
    result %= MOD;
  }

  cout<<result<<endl;

  return 0;

rep(i, n+1){
  rep(j, m+1){
    rep(k,15)cout<<dp[i][j][k]<<' ';cout<<'|';
  }
cout<<endl;
}

  return 0;
}
