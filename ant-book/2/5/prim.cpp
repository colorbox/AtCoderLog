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

  int mincost[n];
  mincost[0]=0;

  bool used[n];
  rep(i, n)used[i]=false;

  priority_queue< pi, vector<pi>, greater<pi> > q;
  q.push({0,0});
  // {cost, from}

  int min_cost = 0;
  while(!q.empty()){
    cout<<q.size()<<endl;
    auto p = q.top();q.pop();
    int from = p.second;
    // 使用済みであれば最小値ではないので飛ばす
    if(used[from])continue;
    // 未使用であれば最小値なので組み入れ、コスト追加
    used[from]=true;
    int from_cost = p.first;
    min_cost += from_cost;

    for(auto t: graph[from]){
      int to = t.second;
      // 未使用のノードはキューに詰める
      if(!used[to]) q.push(t);
    }
  }

  cout<<min_cost<<endl;

  return 0;
}
