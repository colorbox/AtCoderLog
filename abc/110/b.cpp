#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,m,x,y;
  cin>>n>>m>>x>>y;

  int maxx=x;
  rep(i,n){
    int t;cin>>t;
    maxx=max(maxx,t);
  }

  int miny=y;
  rep(i,m){
    int t;cin>>t;
    miny=min(miny, t);
  }

  if(maxx<miny){
    cout<<"No War";
  }else{
    cout<<"War";
  }
  
  return 0;
}
