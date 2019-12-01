#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  int d,x;cin>>d>>x;
  int result=0;
  rep(i, n){
    int a;cin>>a;
    rep(i,d){
      if(1+(i)*a <= d)result+=1;
    }
  }

  cout<<result+x;

  return 0;
}
