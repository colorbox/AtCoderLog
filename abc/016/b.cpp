#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  
  if(a+b==c && a-b==c){
    cout<<'?'<<endl;
  }else if(a+b==c){
    cout<<'+'<<endl;
  }else if(a-b==c){
    cout<<'-'<<endl;
  }else{
    cout<<'!'<<endl;
  }
  return 0;
}
