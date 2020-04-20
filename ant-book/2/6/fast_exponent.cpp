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
  ll n;cin>>n;

  bool is_p=true;
  for(int i=2; i*i<=n; i++)if(n%i==0)is_p=false;
  if(is_p){ cout<<"No"<<endl; return 0; }
  
  bool f=true;
  for(int i=2; i<n; i++)if(!f || modpow(i, n, n)!=i)f=false;
  // for(int i=2; i<n; i++)cout<<modpow(i, n, n)<<' '<<i<<endl;

  cout<<(f ? "Yes" : "No")<<endl;

  return 0;
}
