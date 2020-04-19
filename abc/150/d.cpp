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

map<pll, ll> m;

ll gcd(ll a, ll b){
  if(a==1 || b==1)return 1;
  if (a < b)swap(a,b);
  if(m[{a, b}]>0)return m[{a, b}];

  m[{a, b}] = b ? gcd(b, a % b) : a;
  return m[{a, b}];
}

ll lcm(ll a, ll b){
  return a * b / gcd(a, b);
}

int main(){
  ll n,m;cin>>n>>m;
  vector<ll>a(n);
  rep(i, n)cin>>a[i];
  ll base = 1;
  rep(i, n){
    base = lcm(base, a[i]);
    if(base>m)base=0;
  }

  if(base==0){cout<<0<<endl;return 0;}

  ll result = 0;
  if(m>base/2){
    m-=base/2;
    result++;
  }
  result += m/base;
  cout<<result<<endl;

  return 0;
}
