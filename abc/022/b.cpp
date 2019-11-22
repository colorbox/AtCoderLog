#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;
  cin>>n;

  map<ll, ll> m;
  ll result=0;

  rep(i,n){
    ll t;
    cin>>t;
    if(m[t]==1)result++;
    m[t]=1;
  }
  
  cout<<result<<endl;

  return 0;
}
