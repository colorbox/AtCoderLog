#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;
  cin>>s;

  ll count=1;
  char c;
  c=s[0];
  
  rep(i, s.size()-1){
    if(s[i+1]==c){
      count++;
    }else{
      cout<<c<<count;
      c=s[i+1];
      count=1;
    }
  }
  cout<<c<<count<<endl;
  return 0;
}
