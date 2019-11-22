#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n, x;
  cin>>n>>x;
  vector<int> a;
  rep(i,n){
    ll t;
    cin>>t;
    a.push_back(t);
  }

  ll res=0;
  rep(i,n){
    if(x&1)res+=a[i];
//cout<<(x&1)<<' '<<a[i]<<endl;
    x=x>>1;
  }

  cout<<res<<endl;

  return 0;
}
