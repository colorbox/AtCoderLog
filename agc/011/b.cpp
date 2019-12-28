#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;cin>>n;
  vector<ll> a(n),ca(n);
  rep(i,n){
    cin>>a[i];
    ca[i]=a[i];
  }

  sort(a.begin(), a.end());
  sort(ca.begin(), ca.end());
//rep(i,n)cout<<a[i]<<' ';cout<<endl;

  rep(i,n-1)ca[i+1] = ca[i]+ca[i+1];
//rep(i,n)cout<<a[i]<<' ';cout<<endl;

  ll c=1;
  rep(i,n-1){
    if(ca[i]*2 >= a[i+1])c++;
    else c=1;
  }
  cout<<c<<endl;

  return 0;
}
