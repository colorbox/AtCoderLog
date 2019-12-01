#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int a,b,k;cin>>a>>b>>k;
  int result=0;
  rep(i,b-a+1){
    if(i+a<a+k || i+a>b-k)cout<<i+a<<endl;
  }
  return 0;
}
