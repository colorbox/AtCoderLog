#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  rep(i,s.size()){
    if((i+1)%2==1)cout<<s[i];
  }

  return 0;
}
