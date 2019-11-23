#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll m,ds=0,s=0;
  cin>>m;
  
  ll result=0;
  rep(i,m){
    ll d,c;
    cin>>d>>c;
    ds+=d*c;
    s+=c;
  }
  cout<<(ds-1)/9 + s-1;

  return 0;
}
