#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define ll long long

#define MOD 1000000007

using namespace std;

bool dp[101][100001];
//dp[i][j]:i番目までの数字を使って、jを構築できるか

int main(){
  ll n,k;
  n=3;
  k=17;
  vector<ll> a({3, 5, 8});
  vector<ll> m({3, 2, 2});

  dp[0][0]=true;

  rep(i, n){
    cout<<a[i]<<' '<<m[i]<<endl;
    rep(j, k+1){
      for(int kk=0; kk<=m[i] && kk*a[i] <= j; kk++){
        dp[i+1][j] |= dp[i][j-kk*a[i]];
      }

      rep(l, k+1)cout<<dp[i+1][l]<<' ';cout<<endl;
    }
    cout<<"-------------"<<endl;
  }

  cout<<(dp[n][k]>=0 ? "Yes" : "No")<<endl;

  return 0;
}
