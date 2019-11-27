#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s[3];
  cin>>s[0];
  cin>>s[1];
  cin>>s[2];

  int c=s[0].at(0)-'a';
  s[0].erase(0,1);
  while(true){
    if(s[c].empty())break;
    int t=s[c].at(0)-'a';
    s[c].erase(0,1);
    c=t;
  }

  cout<<(char)(c+'A');
  return 0;
}
