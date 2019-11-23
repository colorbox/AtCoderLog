#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,a,b,p=0;
  cin>>n>>a>>b;
  rep(i,n){
    string s;
    ll d;
    cin>>s>>d;
    if(d<a)d=a;
    if(d>b)d=b;
    if(s=="East"){
      p+=d;
    }else{
      p-=d;
    }
  }
  
  if(p==0){
    cout<<0<<endl;
  }else if(p>0){
    cout<<"East"<<' '<<p<<endl;
  }else{
    cout<<"West"<<' '<<-1*p<<endl;
  }
  
  return 0;
}
