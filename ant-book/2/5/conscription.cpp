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

int n;
int m;
int r;

int main(){
  n = 5, m = 5, r = 8;
  int x[] = {4,1,0,0,3,1,4,2};
  int y[] = {3,3,0,1,3,3,2,2};
  int d[] = {6831, 4583, 6592, 3063, 4975, 2049, 2104, 781};

  vector<pair<int, pi>> pairs;
  rep(i, r){
    auto p = make_pair(x[i], n+y[i]);
    pairs.emplace_back(-d[i], p);
  }

  sort(pairs.begin(), pairs.end());
  rep(i, r)cout<<pairs[i].first<<' '<<pairs[i].second.first<<' '<<pairs[i].second.second<<endl;

  int bonus=0;
  UnionFind uf(n*3);
  rep(i, r){
    auto p = pairs[i].second;

    if(!uf.same(p.first, p.second)){
      cout<<pairs[i].first<<' ';
      uf.unite(p.first, p.second);
      bonus += pairs[i].first;
    }
  }

  cout<<endl;

  cout<<10000*(n+m)+bonus<<endl;

  return 0;
}
