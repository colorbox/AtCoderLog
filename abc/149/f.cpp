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

#define MAXN 200000

// x^n in mod
ll modpow(ll x, ll n, ll mod){
  if(n==0) return 1;

  if(n%2==0){
    return modpow(x*x%mod, n/2, mod) % mod;
  }else{
    return x * modpow(x, (n-1), mod) % mod;
  }
}

int n;
vector<int> to[MAXN];

ll result=0;

int dfs(int v, int p=-1){
  int res=1;
  vector<int> ts;
  for(int u: to[v]){
    if(u==p)continue;
    int t = dfs(u, v);
    res += t;
    ts.push_back(t);
  }
  if(p!=-1)ts.push_back(n-res);

  ll now = modpow(2, n-1, MOD)-1;
  for(int t: ts){
    now -= modpow(2, t, MOD)-1;
    now += MOD;
    now %= MOD;
  }
  result += now;
  result%=MOD;

  return res;
}

int main(){
  cin>>n;
  rep(i, n-1){
    int a,b;cin>>a>>b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  dfs(0);
//cout<<result<<' '<<modpow(2, n, MOD)<<endl;
  ll all = modpow(2, n, MOD);
  result *= modpow(all, MOD-2, MOD);

  cout<<result%MOD<<endl;

  return 0;
}
