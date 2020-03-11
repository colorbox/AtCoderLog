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
  int n;cin>>n;
  vector<ll> g[n+1];
  rep(i, n){
    ll u,k;cin>>u>>k;
    rep(j, k){
      ll t;cin>>t;
      g[u].push_back(t);
    }
  }

  vector<ll>result(n+1);
  rep1(i, n)result[i]=-1;

  result[1]=0;

  queue<ll> q;
  q.push(1);
  while(!q.empty()){
    ll c = q.front();
    q.pop();
    for(auto to: g[c]){
      if(result[to]>=0)continue;

      result[to] = result[c]+1;
      q.push(to);
    }
  }

  rep1(i, n)cout<<i<<' '<<result[i]<<endl;

  return 0;
}
