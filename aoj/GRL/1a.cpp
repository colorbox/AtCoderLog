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

#define MAXV 100000
vector<pll> g[MAXV];
ll d[MAXV];

int main(){
  int v,e,r;cin>>v>>e>>r;
  rep(i, e){
    ll s,t,d;cin>>s>>t>>d;

    g[s].push_back({d, t});
  }

  rep(i, MAXV)d[i]=INF;

  priority_queue< pll, vector<pll>, greater<pll> > q;
  q.push({0, r});
  while(!q.empty()){
    ll dist = q.top().first;
    ll node = q.top().second;
    q.pop();
    if(d[node]<dist)continue;
    d[node]=dist;
    for(auto dist_to: g[node]){
      ll to_dist = d[node]+dist_to.first;
      ll to_node = dist_to.second;
      if(to_dist<d[to_node])q.push({to_dist, to_node});
    }
  }

  rep(i, v){
    if(d[i]==INF)cout<<"INF"<<endl;
    else cout<<d[i]<<endl;
  }

  return 0;
}
