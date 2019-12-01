#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s,t;cin>>s>>t;

  if(s==t){
    cout<<"Yes";return 0;
  }
  rep(i,s.size()){
    s = s.substr(1,s.size()-1)+s[0];
//    cout<<s<<endl;
    if(s==t){
      cout<<"Yes";return 0;
    }
  }

  cout<<"No";
  return 0;
}
