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
  ll n;cin>>n;
  vector<pll> x(n),y(n);
  rep(i,n){
    cin>>x[i].first>>y[i].first;
    x[i].second=y[i].second=i;
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  vector<pair<ll, pi>>edges;
  rep(i, n-1){
    ll xcost = abs(x[i].first-x[i+1].first);
    edges.push_back({xcost, {x[i].second, x[i+1].second}} );

    ll ycost = abs(y[i].first-y[i+1].first);
    edges.push_back({ycost, {y[i].second, y[i+1].second}} );
  }

  sort(edges.begin(), edges.end());

  ll result = 0;
  UnionFind uf(n);
  for(auto p:edges){
    ll a=p.second.first;
    ll b = p.second.second;
    if(!uf.same(a, b)){
      result += p.first;
      uf.unite(a,b);
    }
  }

  cout<<result<<endl;

  return 0;
}
