#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int a,b;cin>>a>>b;
  int result=0;
  rep(i,b-a){
    result+=(i+1);
  }
  result-=b;
  cout<<result;

  return 0;
}
