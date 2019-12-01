#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,x;cin>>n>>x;
  int minx = 1000;
  int sum = 0;
  rep(i,n){
    int t;cin>>t;
    minx=min(t,minx);
    sum+=t;
  }
  
  cout<<(x-sum)/minx+n;

  return 0;
}
