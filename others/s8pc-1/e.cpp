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

// x^n in mod
ll modpow(ll x, ll n, ll mod){
  if(n==0) return 1;

  if(n%2==0){
    return modpow(x*x%mod, n/2, mod) % mod;
  }else{
    return x * modpow(x, (n-1), mod) % mod;
  }
}

int main(){
  int n, q;cin>>n>>q;
  vector<ll> a(n), len(n+1), cum(n+1);
  rep(i, n)cin>>a[i];
  rep1(i, n)len[i]=modpow( a[i-1], a[i], MOD );
  rep1(i, n)cum[i]=cum[i-1]+len[i];

  ll result=0;
  ll from=0, to;
  rep(i, q){
    cin>>to;
    to--;
    ll tf = min<ll>(from, to);
    ll tt = max<ll>(from, to);
    // cout<<(ll)(cum[tt]-cum[tf])<<'='<<cum[tt]<<'-'<<cum[tf]<<':'<<tf<<' '<<tt<<'|'<<from<<' '<<to<<endl;
    result += (cum[tt]-cum[tf]);
    result %= MOD;
    from=to;
  }
//cout<<cum[from]<<endl;
  result += cum[from];
  result %= MOD;

  cout<<result<<endl;

  // rep(i, n+1)cout<<cum[i]<<' ';

  return 0;
}
