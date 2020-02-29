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

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
};

int main(){
  ll n,d,a;cin>>n>>d>>a;
  vector<pll> xh(n);
  rep(i, n)cin>>xh[i].first>>xh[i].second;
  sort(xh.begin(), xh.end());

  ll result=0;
  BIT<ll> bit(n+1);
  rep(i, n){
    ll x = xh[i].first;
    ll h = xh[i].second;
    h -= bit.sum(i);
    if(h<=0)continue;

    ll num = (h+a-1)/a;
    result += num;
    ll damage = num*a;

    bit.add(i, damage);
    ll rx = x+2*d;
    ll j = upper_bound(xh.begin(), xh.end(), pll(rx+1, -1))-xh.begin();
    bit.add(j, -damage);
//cout<<i<<' '<<j<<endl;
  }

  cout<<result;

  return 0;
}
