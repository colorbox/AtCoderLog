#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

const ll MOD = 1e9 + 7;

using namespace std;

int main(){
  int n;cin>>n;
  int c[60];
  rep(i,60)c[i]=0;

  ll result=0;
  rep(i,n){
    ll a;cin>>a;

    rep(j,60){
      ll mask=(1LL<<j);

//      if( (((mask & a)>>j) & 1) != (a >> j)&1 )cout<<(((mask & a)>>j) & 1)<<' '<<((a >> j)&1)<<endl;

//      if((a >> j)&1){
      if(mask & a){
        result += (mask%MOD)*((i-c[j])%MOD);
      }else{
        result += (mask%MOD)*(c[j]%MOD);
      }
      result%=MOD;
    }
    rep(j,60){
      ll mask=(1LL<<j);
      if(mask & a)c[j]++;
    }
  }

  cout<<result;

  return 0;
}
