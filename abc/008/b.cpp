#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;
  cin>>n;
  map<string, int> m;

  rep(i,n){
    string s;
    cin>>s;
    m[s]++;
  }
  
  pair<string, int> result = make_pair("",0);
  for(auto p : m){
    if(p.second > result.second)result = make_pair(p.first, p.second);
  }
  
  cout<<result.first;

  return 0;
}
