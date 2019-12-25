#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll na,nb;cin>>na>>nb;
  set<ll>a,b;
  rep(i,na){
    ll t;cin>>t;
    a.insert(t);
  }
  ll u=0,d=a.size();
  rep(i,nb){
    ll t;cin>>t;
    if(a.count(t)==1)u++;
    else d++;
  }
//cout<<u<<' '<<d<<endl;
  cout<<fixed<<setprecision(12)<<(double)u/(double)d<<endl;
  return 0;
}
