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
  n++;

  rep(i, n)cout<<rc[i]<<' ';cout<<endl;
  rep(i, n-1)cout<<r[i]<<' ';cout<<endl;
  rep(i, n-1)cout<<c[i]<<' ';cout<<endl<<endl;

  rep(i, MAXN)rep(j, MAXN)dp[i][j]=INF;

  rep(i, n-2)dp[i][i+2]=rc[i]*rc[i+1]*rc[i+2];

  rep(i, n){rep(j, n)cout<<dp[i][j]<<' ';cout<<endl;}
  cout<<endl;

  for(int len=3; len<n; len++){
    rep(i, n-len){


      dp[i][i+len] = min( dp[i][i+len-1] +rc[i]*rc[i+len]*rc[i+len-1], 
                          dp[i+1][i+len] +rc[i]*rc[i+len]*rc[i+1]     );
    }
  }

  cout<<dp[0][n-1]<<endl;

  rep(i, n){rep(j, n)cout<<dp[i][j]<<' ';cout<<endl;}
  cout<<endl;

  return 0;
}
