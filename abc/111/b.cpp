#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  rep(i,1000){
    if(i%111==0 && i>=n){
      cout<<i;
      break;
    }
  }

  return 0;
}
