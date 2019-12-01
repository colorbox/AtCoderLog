#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,k;cin>>n>>k;
  int result=0;

  rep(i,n){
    int x;cin>>x;
    result+=2*min(x,abs(k-x));
  }
  cout<<result;

  return 0;
}
