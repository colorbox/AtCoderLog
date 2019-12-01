#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int x;cin>>x;

  int result=1;
  rep(i,x-1){
    int t = 2;
    int c=i+2;
    int pct;
    while((pct=pow(c,t))<=x){
      result = max(result,pct);
      t++;
    }
  }

  cout<<result;

  return 0;
}
