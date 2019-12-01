#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int h,w;cin>>h>>w;

  rep(i,w+2)cout<<"#";
  cout<<endl;

  rep(i,h){
    cout<<"#";
    string s;cin>>s;
    cout<<s;
    cout<<"#"<<endl;
  }

  rep(i,w+2)cout<<"#";

  return 0;
}
