#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n;cin>>n;
  vector<ll> c(n);
  rep(i, n)cin>>c[i];
  c.erase( unique(c.begin(), c.end()), c.end() );
  n = c.size();

  map<ll,ll>lim;
  ll result = 1;
  rep(i,n){
    result += lim[c[i]];
    result %= MOD;
    lim[c[i]]=result;
//cout<<c[i]<<' '<<result<<endl;
  }

  cout<<result;

  return 0;
}
