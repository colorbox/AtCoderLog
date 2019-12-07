#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll k;cin>>k;
  ll n=50;
  ll a[n];
  rep(i,n)a[i]=n-1+k/n;

  rep(i,k%n){
    a[i]+=n;
    rep(j,n)a[j]--;
    a[i]++;
  }

  cout<<n<<endl;
  rep(i,50){
    cout<<a[i]<<' ';
  }

  return 0;
}
