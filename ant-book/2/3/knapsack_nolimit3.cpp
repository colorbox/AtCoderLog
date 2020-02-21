#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int dp[100001];
// dp[j]:重さがjを超えないように選んだ時の価値の総和の最大値

int main(){
  int n,w;
  // cin>>n>>w;
  // vector<int>ws(n),vs(n);
  // rep(i,n)cin>>ws[i];
  // rep(i,n)cin>>vs[i];
  n=3;w=7;
  vector<int>ws({3,4,2});
  vector<int>vs({4,5,3});

  rep(i,n){
    for(int j=ws[i]; j<=w; j++){
      dp[j] = max(dp[j-ws[i]] + vs[i], dp[j]);

      rep(j,w+1)cout<<dp[j]<<' ';
      cout<<endl;
      cout<<"-----------"<<endl;
    }
  }

  cout<<dp[w]<<endl;

  return 0;
}

/*
0 0 0 0 0 0 0 0 
0 0 0 4 4 4 8 8 
0 0 0 4 5 5 8 9 
0 0 3 4 6 7 9 10 
*/
