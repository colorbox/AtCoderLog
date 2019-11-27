#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string w;
  cin>>w;
  map<char, int> m;
  rep(i, w.size()){
    m[(char)w.at(i)]++;
  }
  for(auto p:m){
    if(p.second%2!=0){
      cout<<"No";
      return 0;
    }
  }

  cout<<"Yes";

  return 0;
}
