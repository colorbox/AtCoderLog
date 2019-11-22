#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,t;
  cin>>n>>t;
  
  ll sum=0;
  ll closed=0;
  ll opened=0;
  rep(i,n){
    ll c_opened;
    cin>>c_opened;
    
    if(c_opened>closed){
      sum += (closed-opened);
      opened = c_opened;
    }
    closed = c_opened+t;
  }
  sum += (closed-opened);
  
  cout<<sum<<endl;
  return 0;
}
