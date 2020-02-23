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
  int n=7;

  vector<tuple<int, int, int>> g = {
    make_tuple(0, 1, 2),
    make_tuple(0, 2, 5),
    make_tuple(1, 2, 4),
    make_tuple(1, 3, 6),
    make_tuple(1, 4, 10),
    make_tuple(2, 3, 2),
    make_tuple(3, 5, 1),
    make_tuple(4, 5, 3),
    make_tuple(4, 6, 5),
    make_tuple(6, 5, 9),
  };

  vector<pi> graph[1001];
  rep(i, g.size()){
    int f = get<0>(g[i]);
    int t = get<1>(g[i]);
    int c = get<2>(g[i]);
    graph[f].emplace_back(c, t);
    graph[t].emplace_back(c, f);
  }

  int prev[1001];
  rep(i, 1001)prev[i]=-1;

  priority_queue< pi, vector<pi>, greater<pi> > q;
  q.push({0,0});

  ll d[1001];
  rep(i, n)d[i]=INF;
  d[0]=0;

  while(!q.empty()){
    auto p = q.top();q.pop();
    int from = p.second;
    int from_cost = p.first;

    if(d[from] < from_cost)continue;

    for(auto np: graph[from]){
      int to = np.second;
      int cost = np.first;
      if(d[to] > d[from] + cost ){
        d[to] = d[from] + cost;
        q.push({d[to], to});
        prev[to] = from;
      }
    }
    rep(i,n)cout<<d[i]<<' ';cout<<endl;
  }

  cout<<d[n-1]<<endl;

  vector<int> path; 
  int t = n-1;
  path.push_back(t);
  while(prev[t]!=-1){
    path.push_back(prev[t]);
    t = prev[t];
  }
  reverse(path.begin(), path.end());

  rep(i, path.size())cout<<path[i]<<' ';cout<<endl;

  return 0;
}
