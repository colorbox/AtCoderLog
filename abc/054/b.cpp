#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,m;cin>>n>>m;
  string a[n];
  rep(i,n)cin>>a[i];
  string b[m];
  rep(i,m)cin>>b[i];

  int result;
  rep(i,n-m+1){
    rep(j,n-m+1){
      result=1;
      rep(ii,m)rep(jj,m)if(a[i+ii][j+jj]!=b[ii][jj])result=0;
      if(result){
        cout<<"Yes";
        return 0;
      }
    }
  }
  cout<<"No";

  return 0;
}
