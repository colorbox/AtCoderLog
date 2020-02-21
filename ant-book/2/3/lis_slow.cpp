#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define ll long long

#define MOD 1000000007

using namespace std;

int main(){
  ll n;
  n=5;
  vector<ll> a({4, 2, 3, 1, 8});

  vector<ll> dp(n+1, 0);
  // dp[i]:最後がaiである数列の最長部分列長
  rep(i,n){
    // 部分列帳は絶対に1以上になるので1を入れる
    dp[i+1] = 1;
    for(int j=0; j<i; j++){
      // a[i]よりも小さい要素がiより前にあれば
      if(a[j] < a[i]){
        // iまでのLISに対して下記2つの選択が生じる、
        // すでに求まっているdp[i+1]
        // 今確認したa[i]よりも小さいa[j]の時点でのLISの末尾にa[i]を加えた(+1したもの)
        // この2つの大きい方を選ぶ
        dp[i+1] = max(dp[i]+1, dp[j]+1);
      } 
      rep(i,n+1)cout<<dp[i]<<' ';cout<<endl;
    }
    cout<<"---"<<endl;
  }

  cout<<dp[n]<<endl;

  return 0;
}

/*
---
0 1 1 0 0 0 
---
0 1 1 1 0 0 
0 1 1 2 0 0 
---
0 1 1 2 1 0 
0 1 1 2 1 0 
0 1 1 2 1 0 
---
0 1 1 2 1 2 
0 1 1 2 1 2 
0 1 1 2 1 2 
0 1 1 2 1 3 
---
3

*/
