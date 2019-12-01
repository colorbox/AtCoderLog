#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  int sum=0,maxp=0;
  
  rep(i,n){
    int t;cin>>t;
    sum+=t;
    maxp=max(maxp, t);
  }

  cout<<sum-maxp/2;

  return 0;
}
