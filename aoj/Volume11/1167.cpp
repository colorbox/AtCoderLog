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

#define MAXN 999999

int tetrahedrons[MAXN];
int triangles[MAXN];

int dp[MAXN];
int odp[MAXN];

int main(){
  rep1(i, MAXN-1){
    triangles[i] = triangles[i-1] + i;
    tetrahedrons[i] = triangles[i] + tetrahedrons[i-1];
  }

  rep(i, MAXN)dp[i]=INF;
  dp[0]=0;
  rep(i, 2000){
    rep1(j, MAXN){
      int c = tetrahedrons[i];

      if(j-c>=0)dp[j] = min<ll>(dp[j], dp[j-c]+1);
    }
  }

  rep(i, MAXN)odp[i]=INF;
  odp[0]=0;
  rep(i, 2000){
    rep1(j, MAXN){
      int c = tetrahedrons[i];
      if(c%2==0)continue;

      if(j-c>=0)odp[j] = min<ll>(odp[j], odp[j-c]+1);
    }
  }

  while(true){
    int n;cin>>n;
    if(n==0)break;

    cout<<dp[n]<<' '<<odp[n]<<endl;

  }

  return 0;
}
