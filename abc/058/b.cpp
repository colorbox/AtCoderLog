#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string o,e;cin>>o>>e;

  rep(i, max(o.size(), e.size()) ){
    if(i<o.size())cout<<o[i];
    if(i<e.size())cout<<e[i];
  }

  return 0;
}
