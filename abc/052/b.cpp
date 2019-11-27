#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,x=0;
  cin>>n;
  string s;
  cin>>s;
  int result=0;
  rep(i,n){
    if(s[i]=='I'){
      x++;
      if(x>result)result=x;
    }else{
      x--;
    }
  }

  cout<<result;
  return 0;
}
