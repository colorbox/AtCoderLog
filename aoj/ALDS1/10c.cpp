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

#define MAXLEN 1001
int dp[MAXLEN][MAXLEN];

int main(){
  int n;cin>>n;
  rep(i, n){
    rep(i, MAXLEN)rep(j, MAXLEN)dp[i][j]=0;

    string l,r;cin>>l>>r;
    rep(x, l.size())rep(y, r.size()){
      if(l[x]==r[y]) dp[x+1][y+1] = dp[x][y]+1;
      else dp[x+1][y+1] = max(dp[x+1][y], dp[x][y+1]);

    // cout<<r[x]<<' '<<l[y]<<endl;
    // rep(x, l.size()+1){
    //   rep(y, r.size()+1)cout<<dp[x][y]<<' ';cout<<endl;
    // }
    // cout<<"#######"<<endl;

    }

    cout<<dp[l.size()][r.size()]<<endl;

  }
  return 0;
}
