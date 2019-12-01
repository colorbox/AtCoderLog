#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  string s;cin>>s;
  int result=0;

  set<char> l;
  result=0;
  rep(i,n){
    l.insert(s[i]);
    set<char> r;
    rep(j,s.size()-i-1){
      r.insert(s[i+j+1]);
    }

    int tr=0;
    for(auto p:l){
      if(r.count(p)==1)tr++;
    }
    result=max(result, tr);
  }

  cout<<result;
  return 0;
}
