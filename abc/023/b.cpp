#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;
  string s;
  cin>>n;
  cin>>s;
  
  string res = "b";
  rep(i, n/2){
    if(i%3==0){
      res = "a" + res + "c";
    }else if(i%3==1){
      res = "c" + res + "a";
    }else{
      res = "b" + res + "b";
    }
  }
  
  if(res==s){
    cout<<(n/2)<<endl;
  }else{
    cout<<-1<<endl;
  }

  return 0;
}
