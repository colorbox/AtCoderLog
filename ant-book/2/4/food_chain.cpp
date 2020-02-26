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
  int n=100, k=7;
  vector<pair<int, pi>> xy({
    {1,{101,1}},
    {2,{1,2}},
    {2,{2,3}},
    {2,{3,3}},
    {1,{1,3}},
    {2,{3,1}},
    {1,{5,5}},
  });

  UnionFind uf(3*n);
  int result = 0;
  rep(i, k){
    int x = xy[i].second.first;
    int y = xy[i].second.second;
    cout<<xy[i].first<<':'<<x<<' '<<y<<endl;
    if(x<=0 || x>100 || y<=0 || y>100){
      result++;
      continue;
    }

    if(xy[i].first == 1){
      cout<<1<<'*'<<(uf.same(x, y+n) || uf.same(x, y+2*n))<<endl<<endl;
      if(uf.same(x, y+n) || uf.same(x, y+2*n))result++;
      else{
        uf.unite(x, y);
        uf.unite(x+n, y+n);
        uf.unite(x+2*n, y+2*n);
      }
    }else{
      cout<<2<<'*'<<uf.same(x, y)<<endl<<endl;
      if(uf.same(x, y))result++;
      else{
        uf.unite(x, y+n);
        uf.unite(x+n, y+2*n);
        uf.unite(x+2*n, y);
      }
    }
  }

  cout<<result<<endl;

  return 0;
}
