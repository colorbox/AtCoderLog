#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 10000000000000LL

using namespace std;
#define MAXN 5000

ll n,k;
ll d[MAXN];
vector<ll> og[MAXN];
vector<pll> g[MAXN];
pll company[MAXN];

int visited[MAXN];
void dfs(ll from, ll now, ll remain){
  if(remain==-1) return;
  if(visited[now]>remain) return;

  visited[now]=remain;
  if(from!=now)g[from].push_back({company[from].first, now});
  for(auto to: og[now]){
    dfs(from, to, remain-1);
  }
}

int main(){
  cin>>n>>k;
  rep(i, n){ cin>>company[i].first>>company[i].second; }
  rep(i, k){
    ll a,b;cin>>a>>b;a--;b--;
    og[a].push_back(b);
    og[b].push_back(a);
  }

  rep(from, n){
    ll remain = company[from].second;
    rep(i, n)visited[i]=-1;
    g[from].push_back({0, from});
    visited[from]=0;
    dfs(from, from, remain);
  }

  rep(i, n)d[i]=INF;
  priority_queue<pi, vector<pi>, greater<pi>>q;
  q.push({0, 0});
  while(!q.empty()){
    ll from_cost = q.top().first;
    ll from_node = q.top().second;
    q.pop();

    if(d[from_node]<=from_cost)continue;
    d[from_node] = from_cost;
    for(auto cost_to: g[from_node]){
      ll to_cost = cost_to.first+d[from_node];
      ll to_node = cost_to.second;

      q.push({to_cost, to_node});
    }
  }

  cout<<d[n-1]<<endl;

 return 0;

  rep(i, n)cout<<d[i]<<' ';cout<<endl;

 rep(from, n){for(auto cost_to: g[from])cout<<cost_to.second<<' ';cout<<endl;}

  return 0;
}
