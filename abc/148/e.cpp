#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

ll f(ll n){
  if(n<2)return 1;
  return n*f(n-2);
}

int main(){
  ll n;cin>>n;
  if(n%2==1){
    cout<<0;return 0;
  }

  ll result=0;
  n/=2;
  while(n>0){
    result += n/5;
    n/=5;
  }

  cout<<result;

  return 0;
}
