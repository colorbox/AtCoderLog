#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,t;cin>>n>>t;

  int c=1001;
  rep(i,n){
    int tc,tt;cin>>tc>>tt;
    if(tc<c && tt<=t){
      c=tc;
    }
  }
  if(c!=1001){
    cout<<c;
  }else{
    cout<<"TLE";
  }

  return 0;
}
