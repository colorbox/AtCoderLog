#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;
  int t;
  cin>>s;
  cin>>t;
  int x=0,y=0,result=0;

  rep(i,s.size()){
    if(s[i]=='U')y++;
    if(s[i]=='D')y--;
    if(s[i]=='R')x++;
    if(s[i]=='L') x--;
    if(s[i]=='?') result++;
  }

  int tmp = (abs(x)+abs(y));
  if(t==2){
    result = tmp-result;
    if(result<0){result = abs(result)%2;}
  }else{
    result += tmp;
  }

  cout<<result<<endl;

  return 0;
}
