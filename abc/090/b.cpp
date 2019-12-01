#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int a,b;cin>>a>>b;

  int result=0;
  rep(i, b-a+1){
    string s = to_string(i+a);
    string rs = s;
    reverse(rs.begin(),rs.end());

    if(s==rs)result++;
  }
  cout<<result;

  return 0;
}
