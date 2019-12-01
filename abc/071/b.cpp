#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;

  map<char, int> m;
  rep(i,s.size()){
    m[s[i]]++;
  }
  rep(i,26){
    if(!m['a'+i]){
      cout<<(char)('a'+i);
      return 0;
    }
  }
  cout<<"None";

  return 0;
}
