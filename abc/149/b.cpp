#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll a,b,k;cin>>a>>b>>k;
  ll l,r;
  l=a-k;
  if(b+l<0){
    cout<<0<<' '<<0;
  }else if(l<0){
    cout<<0<<' '<<b+l;
  }else{
    cout<<l<<' '<<b;
  }

  return 0;
}
