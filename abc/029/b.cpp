#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;
  int result=0;
  rep(i,12){
    cin>>s;
    rep(i, s.size()){
      if(s[i]=='r'){
        result++;
          break;
      }
    }
  }
  
  cout<<result<<endl;
  return 0;
}
