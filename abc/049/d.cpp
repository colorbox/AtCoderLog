#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> par, rank;

  UnionFind(int n){
    par.resize(n);
    fill(par.begin(), par.end(), -1);
    rank.resize(n);
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
  int n,k,l;
  cin>>n>>k>>l;

  UnionFind roads = UnionFind(n);
  UnionFind rails = UnionFind(n);

  for(int i=0;i<k;i++){
    int p,q;
    cin>>p>>q;
    roads.unite(p,q);
  }
  for(int i=0;i<l;i++){
    int r, s;
    cin>>r>>s;
    rails.unite(r,s);
  }

  map<pair<int, int>, int> counter;

  for(int i=0;i<n;i++){
    counter[make_pair(roads.root(i-1), rails.root(i-1))]++;
  }

  for(int i=0;i<n;i++){
    cout<<counter[make_pair(roads.root(i-1), rails.root(i-1))]<<' ';
  }

  return 0;
}