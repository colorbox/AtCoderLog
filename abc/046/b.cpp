#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n, k, result=1;
  cin>>n>>k;

  result=k;
  rep(i, n-1){
    result *= (k-1);
  }

  cout<<result;

  return 0;
}
