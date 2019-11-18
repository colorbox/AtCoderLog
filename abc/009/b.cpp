#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;
  cin>>n;

  vector<ll> a;
  rep(i,n){
    ll t;
    cin>>t;
    a.push_back(t);
  }

  
  sort(a.begin(), unique(a.begin(),a.end()), greater<ll>());

  cout<<a[1]<<endl;
  
  return 0;
}
