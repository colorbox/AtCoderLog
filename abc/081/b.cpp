#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  int result=200;
  rep(i,n){
    int t;cin>>t;
    int tr=0;
    while(t%2==0){
      tr++;
      t/=2;
    }
    result = min(result, tr);
  }

  cout<<result;

  return 0;
}
