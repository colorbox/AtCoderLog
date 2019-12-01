#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int a,b;cin>>a>>b;

  string s;cin>>s;

//cout<<(count(s.begin(), s.end(), '-')!=1);
//cout<<(s.size()!=a+b+1);
//cout<<(s[a]!='-');


  if(count(s.begin(), s.end(), '-')!=1 || s.size()!=a+b+1 || s[a]!='-'){
    cout<<"No";
  }else{
    cout<<"Yes";
  }
  return 0;
}
