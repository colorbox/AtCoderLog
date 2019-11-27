#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int k,s;
  cin>>k>>s;
  int result=0;
  rep(i,k+1){
    rep(j,k+1){
      if(0<=s-i-j && s-i-j <= k)result++;
    }
  }

  cout<<result;
  return 0;
}
