#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

ll dp[500001];

int main(){
  int n,m;cin>>n>>m;
  rep(i, n+1)dp[i]=INF;
  dp[0]=0;

    rep(i, m){
    int c;cin>>c;
    rep1(j, n)if(j-c>=0)dp[j]=min<ll>(dp[j], dp[j-c]+1);
  }

  cout<<dp[n]<<endl;
Î
  return 0;
}
