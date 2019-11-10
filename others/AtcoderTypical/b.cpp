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
    for(int i=0;i<8;i++){
      cout<<par[i]<<' ';
    }
    cout<<endl;
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

  int n,q;
  cin>>n>>q;

  UnionFind uf = UnionFind(n);
  int p,a,b;
  for(int i=0;i<q;i++){
    cin>>p>>a>>b;

    if(p==0){
      uf.unite(a,b);
    }else{
      if(uf.is_same(a,b)){
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }
  }

  return 0;
}
