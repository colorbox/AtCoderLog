#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;
  cin>>s;
  int k;
  cin>>k;

  if(k>s.size()){
    cout<<0<<endl;
    return 0;
  }

  map<string, int> m;
  rep(i, s.size()-k+1){
    m[s.substr(i,k)]++;
  }

  cout<<m.size()<<endl;
  return 0;
}
