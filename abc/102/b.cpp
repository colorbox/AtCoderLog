#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  int ma=0,mi=1e9;
  rep(i,n){
    int t;cin>>t;
    mi=min(mi, t);
    ma=max(ma, t);
  }

  cout<<ma-mi;

  return 0;
}
