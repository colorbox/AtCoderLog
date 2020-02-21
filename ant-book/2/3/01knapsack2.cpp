#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int dp[11];
// dp[j]:重さjで実現可能な最大価値

int main(){
  int n, w;
  // vector<int>ws(n),vs(n);
  n = 4;w=5;
  vector<int> ws({2,1,3,2});
  vector<int> vs({3,2,4,2});


  // cin>>n>>w;
  // rep(i,n)cin>>ws[i];
  // rep(i,n)cin>>vs[i];

  for(int i=0; i<n; i++){
    for(int j=w; j>=ws[i]; j--){
      dp[j] = max( dp[j], dp[j-ws[i]]+vs[i]);

      rep(i,w+1)cout<<dp[i]<<' ';cout<<endl;
      cout<<"-----------"<<endl;

    }
  }

  cout<<dp[w];

  return 0;
}
