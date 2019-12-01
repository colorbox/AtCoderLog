#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;

  bool result=true;
  string subs = s.substr(2,s.size()-2);
  if(s[0]!='A' || s[s.size()-1]=='C' || count(subs.begin(), subs.end(), 'C')!=1){cout<<"WA";return 0;}

  rep(i,s.size()-1){
    int c=i+1;
    if( !(s[c]=='C' || s[c]!='C' && 'a' <= s[c] && s[c]<'z') )result=false;
//    cout<<s[c]<<' '<<result<<endl;
  }

  if(result){
    cout<<"AC";
  }else{
    cout<<"WA";
  }

  return 0;
}
