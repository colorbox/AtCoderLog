#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long
#define MOD 1000000007

using namespace std;

int main(){
  int n;cin>>n;
  ll result=1;

  rep(i,n){
    result *= (i+1);
    result %= MOD;
  }
  cout<<result;

  return 0;
}
