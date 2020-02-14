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

  vector<ll> dp(n, MOD);
  rep(i,n){
    *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }

  auto it = lower_bound(dp.begin(), dp.end(), MOD);
  cout<<(int)(it-dp.begin())<<endl;
  rep(i,n)cout<<dp[i]<<' ';cout<<endl;


  return 0;
}
