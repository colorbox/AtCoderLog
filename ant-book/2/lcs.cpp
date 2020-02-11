#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int dp[11][11];
//dp[i][j]:文字列sのインデックスiまでと文字列tのインデックスjまでの最大一致部分列の長さ


int main(){
  string s,t;
  //cin>>s>>t;
  s = "abcd";
  t = "becd";

  rep(i, s.size()){
    rep(j, t.size()){
      if( s[i]==t[j] ){
        // 今見ている2つの文字列の末尾が同一なので、問答無用で+1する。
        dp[i+1][j+1] = dp[i][j]+1;
      }else{
        // 今見ている2つの文字列を比較。
        // 着目している2つの文字列の末尾が異なる文字だったため、既存のLCSを持ってくる。
        // 2つの値があるが、長い方を持ってくる。
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }
   rep(i, s.size()+1){
   rep(j, t.size()+1)cout<<dp[i][j]<<' ';
   cout<<endl;
   }
   cout<<"-------------"<<endl; z 

  }

  cout<<dp[s.size()][t.size()]<<endl;

  return 0;
}
