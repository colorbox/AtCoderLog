#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

#define MOD 1000000007

// x^n in mod
ll mod_pow(ll x, ll n){
  if(n==0) return 1;

  if(n%2==0){
    return mod_pow(x*x%MOD, n/2) % MOD;
  }else{
    return x * mod_pow(x, (n-1)) % MOD;
  }
}

ll mod_pow_r(ll x, ll n){
  if(x==0)return 0;
  if(n==0) return 1;

  ll ret = 1;
  while(n){
    if(n&1) ret=ret*x%MOD;
    n /= 2;
    x=x*x%MOD;
  }
  
  return ret;
}


ll fac(ll n){
  ll res = 1;
  rep(i, n){
    res *= (i+1);
    res %= MOD;
  }
  return res;
}

// nCr
ll comb(ll n, ll r){
  if(n<0 || n<r || r<0)return 0;
  ll fn = fac(n);
  ll fr = fac(r);
  ll fn_r = fac(n-r);
  
  ll d = (mod_pow(fr, MOD-2)*mod_pow(fn_r, MOD-2))%MOD;
  ll u = fn%MOD;

  return u * d % MOD;
}

int main(){
  ll x,y;
  cin>>x>>y;
  
  if((x+y)%3!=0){
    cout<<0;
    return 0;
  }

  ll k = x-(x+y)/3;
  ll l = y-(x+y)/3;

//  cout<<k<<' '<<l<<endl;
  cout<<comb(k+l, k);

  return 0;
}
