#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int result=0;
  int a=-1,z;
  string s;cin>>s;

  rep(i,s.size()){
    if(s[i]=='A' && a==-1)a=i;

    if(s[i]=='Z')z=i;
  }
  cout<<z-a+1;
  return 0;
}
