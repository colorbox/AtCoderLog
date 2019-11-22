#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,a,b,k;
  cin>>n;
  cin>>a>>b;
  cin>>k;
  map<ll,ll> m;
  m[a]=1;
  m[b]=1;
  rep(i,k){
    ll t;
    cin>>t;
    if(m[t]>0){

      cout<<"NO"<<endl;
      return 0;
    }else{
      m[t]=1;
    }
  }
  cout<<"YES"<<endl;

  return 0;
}
