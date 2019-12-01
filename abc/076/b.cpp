#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,k;cin>>n>>k;

  int result=1;
  rep(i,n){
    if(result<=k){
      result*=2;
    }else{
      result+=k;
    }
  }

  cout<<result;
  return 0;
}
