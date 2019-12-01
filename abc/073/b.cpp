#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  int result=0;
  rep(i,n){
    int l,r;cin>>l>>r;
    result+=(r-l+1);
  }

  cout<<result;
  return 0;
}
