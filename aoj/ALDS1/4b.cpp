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

int main(){
  ll n;cin>>n;

  vector<ll>s(n);
  rep(i, n)cin>>s[i];

  ll q;cin>>q;

  vector<ll>t(q);
  rep(i, q)cin>>t[i];

  ll result = 0;
  for(auto p: t){
    auto c = *lower_bound(s.begin(), s.end(), p);
    if(c==p)result++;
    // cout<<c<<' '<<p<<endl;
  }

  cout<<result<<endl;

  return 0;
}
