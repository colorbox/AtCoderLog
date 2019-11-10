#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

struct UnionFind {
  vector<int> par, rank;

  UnionFind(int n){
    par.resize(n+1);
    fill(par.begin(), par.end(), -1);
    rank.resize(n+1);
  }

  int root(int x){
    if(par[x] < 0){
      return x;
    }

    par[x] = root(par[x]);

    return par[x];
  }

  void unite(int x, int y){
    int rx=root(x);
    int ry=root(y);

    if(rx!=ry){
      if(rank[rx] >= rank[ry]){
        par[ry]=rx;

        if(rank[rx]==rank[ry]){
          rank[rx] += 1;          
        }
      }else{
        par[rx] = ry;
      }
    }
  }

  bool is_same(int x, int y){
    return root(x)==root(y);
  }

  int count(int x){
    return -par[root(x)];
  }
};

int main(){
  int n,k;
  scanf("%d %d", &n, &k);
  // cin>>n>>k;
  UnionFind uf(3*n);
  int result=0;

  rep(i, k){
    int d,x,y;
    // cin>>d>>x>>y;
    scanf("%d %d %d", &d, &x, &y);

    if(x < 1 || x>n || y<1 || y>n){
      result++;
      continue;
    }
    
    if(d==1){
      // xとyが同じ種族であるという情報に対して、xがyを食う、yがxを食うという情報は矛盾する
      if(uf.is_same(x, y+n) || uf.is_same(x, y+2*n)){
        result++;
      }else{
        uf.unite(x,y);
        uf.unite(x+n,y+n);
        uf.unite(x+2*n,y+2*n);
      }
    }else{
      // xがyを食うという情報に対して、xとyが同じ種族である、もしくはyがxを食うという除法は矛盾する。
      if(uf.is_same(x,y) || uf.is_same(y+2*n, x)){
        result++;
      }else{
        uf.unite(x,y+n);
        uf.unite(x+n,y+2*n);
        uf.unite(x+2*n,y);
      }
    }
  }

  // cout<<result;
  printf("%d\n", result);

  return 0;
}
