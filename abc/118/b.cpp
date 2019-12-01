#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,mm;cin>>n>>mm;
  map<int,int> m;
  rep(i,n){
    int k;cin>>k;
    rep(j,k){
      int tt;cin>>tt;
      m[tt]++;
    }
  }
  int result=0;
  for(auto p:m){
    if(p.second==n)result++;
  }

  cout<<result;
  return 0;
}
