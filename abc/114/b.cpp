#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;

  int result=1000;
  rep(i,s.size()-2){
    int c = stoi(s.substr(i,3));
    result = min(result, abs(753-c));
  }

  cout<<result;
  return 0;
}
