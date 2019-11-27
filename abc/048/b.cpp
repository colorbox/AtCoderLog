#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll a,b,x, result=0;
  cin>>a>>b>>x;
  if(a==0){
    result=b/x+1;
  }else{
    result = b/x-(a-1)/x;
  }


  cout<<result;
  return 0;
}
