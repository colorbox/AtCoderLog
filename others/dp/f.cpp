// from https://atcoder.jp/contests/dp/submissions/3937222
#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

ll dp[3001][3001];

int main(){
  string s,t;cin>>s>>t;
  rep(i, s.size())rep(j, t.size()){
    if(s[i]==t[j]) dp[i+1][j+1] = dp[i][j]+1;
    else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
  }

//  cout<<dp[s.size()][t.size()]<<endl;

//  rep(i, s.size()+1){
//    rep(j, t.size()+1) cout<<dp[i][j]<<' '; cout<<endl;
//  }

  vector<char> result;
  int i=s.size();
  int j=t.size();
  while(i+j){
    ll c = dp[i][j];
    // s[i]==t[j]である瞬間を捕まえたいので、その瞬間をDPテーブルを移動しながら探す。
    // ty区アモクしているDPテーブルのマスの左と上が同じ値だと、そこはそうではないので移動する。
    // DPテーブル上の左マスの値と、今着目しているマスの値が同じなら左にシフトさせる
    if( i && dp[i-1][j]==c) i--;
    // DPテーブル上の上マスの値と、今着目しているマスの値が同じなら上にシフトさせる
    else if( j && dp[i][j-1]==c) j--;
    else {
      result.push_back(s[i-1]);
      i--;j--;
    }
  }

//cout<<i<<j<<endl;

  rrep(i,result.size())cout<<result[i];
  cout<<endl;

  return 0;
}
