#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define ll long long

#define MOD 1000000000000000LL


ll dp[1001][10001];
// dp[i][j]:i番目の魔法でjのHPを削るのに必要な最小MP

using namespace std;

int main(){
  ll h,n;cin>>h>>n;
  vector<ll>a(n),b(n);
  rep(i, n)cin>>a[i]>>b[i];

  fill(dp[0], dp[0]+1001*10001, MOD);

  dp[0][0]=0;
  rep(i, n){
    rep(j, h+1){

      // i番目の魔法で体力jを削りきれるならi番目の魔法の消費MPを記録
      if(j-a[i]<0)dp[i+1][j]=min(dp[i][j], b[i]);
      // 削りきれないなら、その時わかっている最小消費MPと、i番目の魔法を使った時の消費MPを比較する
      else dp[i+1][j] = min( dp[i][j], dp[i+1][j-a[i]]+b[i] );

    }
  }

  cout<<dp[n][h]<<endl;

  //rep(i, n+1){rep(j, h)cout<<dp[i][j]<<' ';cout<<endl;}

  return 0;
}
