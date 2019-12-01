#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  vector<int> a(n+1);
  rep(i,n)cin>>a[i+1];

  int c=1,result=0;

  rep(i,n){
    if(c==2){
      cout<<result;
      return 0;
    }
    c=a[c];
    result++;
  }
  cout<<-1;
  return 0;
}
