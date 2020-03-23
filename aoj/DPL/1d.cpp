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

#define MAXN 100001
vector<int> dp(MAXN, INF);

int main(){
  int n;cin>>n;
  vector<int> a(n);
  rep(i, n)cin>>a[i];

  rep(i, n)*lower_bound(dp.begin(), dp.end(), a[i]) = a[i];

  auto it = lower_bound(dp.begin(), dp.end(), INF);
  cout<<distance(dp.begin(), it)<<endl;

// rep(i, n)cout<<dp[i]<<' ';

  return 0;
}
