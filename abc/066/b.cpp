#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  int result=0;
  rep(i,s.size()-1){
    if((i+1)%2!=0)continue;
    if(s.substr(0, (i+1)/2) == s.substr((i+1)/2, (i+1)/2))result = max(result, (i+1));
  }

  cout<<result;
  return 0;
}
