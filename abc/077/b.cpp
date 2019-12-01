#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  int result=1;
  rep(i,n+1){
    if(pow(i,2)>n){
      result = (int)pow(i-1,2);
      break;
    }
  }

  cout<<result;

  return 0;
}
