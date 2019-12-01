#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  string last="";
  map<string,int> m;
  rep(i,n){
    string now;cin>>now;
    if(last.size()!=0 && last.at(last.size()-1)!=now[0] || m[now]>0){
      cout<<"No";return 0;
    }
    m[now]++;
    last=now;
  }

  cout<<"Yes";
  return 0;
}
