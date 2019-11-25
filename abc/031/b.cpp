#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int l,h,n;
  cin>>l>>h;
  cin>>n;
  rep(i,n){
    int t;
    cin>>t;
    if(t>h){
      cout<<-1<<endl;
    }else if(l<=t){
      cout<<0<<endl;
    }else{
      cout<<l-t<<endl;
    }
  }  

  return 0;
}
