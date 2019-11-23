#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;
  cin>>n;
  vector<ll> a;
  rep(i, n){
    ll t;
    cin>>t;
    a.push_back(t);
  }
  ll l=0,r=0,lcount=0,rcount=0;
  rep(i, n){
    if(l>r){
      r+=a[n-1-rcount];
      rcount++;
    }else{
      l+=a[lcount];
      lcount++;
    }
  }
  cout<<abs(r-l);

  return 0;
}
