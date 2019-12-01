#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  map<char, int> m;
  rep(i,n){
    char t;cin>>t;
    m[t]++;
  }

  if(m.size()==3){
    cout<<"Three";
  }else{
    cout<<"Four";
  }

  return 0;
}
