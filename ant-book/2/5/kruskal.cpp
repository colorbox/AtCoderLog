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

struct UnionFind {
  vector<int> data;

  UnionFind(int n){
    data.resize(n+1);
    fill(data.begin(), data.end(), -1);
  }

  int root(int x){
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  void unite(int x, int y){
    int rx=root(x);
    int ry=root(y);

    if(rx!=ry){
      if(data[ry] < data[rx])swap(rx, ry);

      data[rx]+=data[ry];
      data[ry]=rx;
    }
  }

  bool same(int x, int y){
    return root(x)==root(y);
  }

  int size(int x){
    return -data[root(x)];
  }
};

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

  vector< pair<int, pi> > edges;
  rep(i, g.size()){
    int f = get<0>(g[i]);
    int t = get<1>(g[i]);
    int c = get<2>(g[i]);
    auto pp = make_pair(f, t); 
    edges.emplace_back(c, pp);
  }

  sort(edges.begin(), edges.end());

  int min_cost = 0;
  UnionFind uf(n);
  for(auto p: edges){
    int cost = p.first;
    auto pp = p.second;

    if(!uf.same(pp.first, pp.second)){
      min_cost += cost;
      uf.unite(pp.first, pp.second);
    }
    cout<<min_cost<<endl;
  }

  cout<<min_cost<<endl;

  return 0;
}
