#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;
  cin>>s;
  string r;

  rep(i,s.size()){
    if(s.at(i)=='B'){
      if(r.size()!=0)r.erase(r.size()-1);
    }else{
      r+=s.substr(i,1);
    }
  }

  cout<<r;

  return 0;
}
