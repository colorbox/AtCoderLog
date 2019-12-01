#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  map<char, int> m;
  rep(i,s.size()){
    char c = s[i];
    m[c]++;
    if(m[c]>1){
      cout<<"no";
      return 0;
    }
  }
  cout<<"yes";

  return 0;
}
