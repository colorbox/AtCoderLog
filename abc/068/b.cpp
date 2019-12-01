#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  rep(i,n+1){
    if(n < 1<<i){
      cout<<(1<<(i-1));
      break;
    }
  }

  return 0;
}
