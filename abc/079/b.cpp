#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;cin>>n;
  ll r[3] = {2,1,3};
  if(n<=2){
    cout<<r[n];
    return 0;
  }
  rep(i,n-2){
    ll t = r[1]+r[2];
    r[0]=r[1];
    r[1]=r[2];
    r[2]=t;
  }

  cout<<r[2];
  return 0;
}
