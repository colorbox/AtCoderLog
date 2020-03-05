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

int dp[101][102];

int main(){
  // int p=20,q=3;
  // vector<int>a({3, 6, 14});

  // int p=8,q=1;
  // vector<int>a({3});

  int p,q;cin>>p>>q;
  vector<int>a(q+2);
  a[0]=0;
  a[q+1]=q+1;
  rep1(i, q)cin>>a[i];
  
  // rep(i, q+1)dp[i][i+1]=0;

  for(int w=2; w<=q+1; w++){
    for(int i=0; i+w<=q+1; i++){
      int t = 1000000;
      int j = i+w;

      for(int k=i+1; k<j; k++){
        t = min(t, dp[i][k] + dp[k][j]);
      }

      dp[i][j] = t + (a[j] - a[i] - 2);

      // rep(i, q+1){
      //   rep(j, q+2)cout<<dp[i][j]<<' ';
      //   cout<<endl;
      // }
      // cout<<"#####"<<endl;

    }
  }

  cout<<dp[0][q+1]<<endl;

  return 0;
}
