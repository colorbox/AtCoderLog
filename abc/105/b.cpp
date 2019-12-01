#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

bool buyable(int money){
  if(money>=7)return buyable(max(0,money-7)) || buyable(max(0,money-4));
  if(money>=4)return buyable(max(0,money-4));
  if(money==0)return true;
  return false;
}

int main(){
  int n;cin>>n;

  if(buyable(n)){
    cout<<"Yes";
  }else{
    cout<<"No";
  }

  return 0;
}
