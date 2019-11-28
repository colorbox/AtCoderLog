#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string a,b;cin>>a>>b;
  if(a.size()<b.size()){
    rep(i,b.size()-a.size()){
      a = "0"+a;
    }
  }else{
    rep(i,a.size()-b.size()){
      b = "0"+b;
    }
  }

  if(a>b){
    cout<<"GREATER";
  }else if(a<b){
    cout<<"LESS";
  }else{
    cout<<"EQUAL";
  }
  return 0;
}
