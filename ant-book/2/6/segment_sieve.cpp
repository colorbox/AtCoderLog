#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXRANGE 10000000
#define MAXB 10000000
bool p[MAXB+1];
bool range_p[MAXRANGE+1];

int main(){
  ll a,b;cin>>a>>b;
  rep(i, MAXB+1)p[i]=true;
  p[0]=p[1]=false;

  rep(i, MAXRANGE+1)range_p[i]=true;

  for(ll i=2; i*i<=b; i++){
    if(!p[i])continue;
    // cout<<i<<endl;
    // [2...√b)
    for(ll j=i*2; j*j<=b; j+=i)p[j]=false;
    // [a...b)
//    for(ll j=max<ll>(2LL, ((a+i-1)/i))*i; j<b; j+=i)cout<<j<<',';cout<<endl;
    for(ll j=max<ll>(2LL, ((a+i-1)/i))*i; j<b; j+=i)range_p[j-a]=false;
    // (a+i-1)/i)は、素数iがaを超えるのに必要な個数a/iの切り上げ=(a+i-1)/iによって、必ず超えるギリギリを算出している。
  }
  ll result = 0;
  for(ll i=a; i<b; i++)if(range_p[i-a])result++;

  cout<<result<<endl;

  for(ll i=a; i<b; i++)if(range_p[i-a])cout<<i<<' ';

  return 0;
}

/*
22 37
3

22801763489 22801787297
1000
*/
