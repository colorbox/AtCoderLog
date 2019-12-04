#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,k;cin>>n>>k;
  ll a[n];rep(i,n){cin>>a[i];}

  ll result=0;
  for(int d=41;d>=-1;d--){
    if( d!=-1 && !(k & (1LL<<d)) )continue;

    ll tmp=0;
    for(int e=40;e>=0;e--){
      ll mask = 1LL<<e;
      ll num=0;
      rep(i,n)if(mask & a[i])num++;

      if(e>d){
        if(k & mask) tmp += mask*(n-num);
        else tmp += mask*num;
      }else if(e==d){
        tmp += mask*num;
      }else{
        tmp += mask*max(num, n-num);
      }
    }
    result = max(result, tmp);
  }

  cout<<result;

  return 0;
}
