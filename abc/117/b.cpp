#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  int sum=0,maxl=0;
  rep(i,n){
    int l;cin>>l;
    sum+=l;
    maxl=max(maxl,l);
  }

  if(maxl<sum-maxl){
    cout<<"Yes";
  }else{
    cout<<"No";
  }

  return 0;
}
