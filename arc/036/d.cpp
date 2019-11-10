#include<bits/stdc++.h>

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
  ll n,q;
  cin>>n>>q;
  UnionFind uf = UnionFind(2*n+1);

  rep(i, q){
    ll w,x,y,z;
    cin>>w>>x>>y>>z;
    if(w==1){

      if(z%2==0){
        uf.unite(x,y);
        uf.unite(x+n,y+n);
      }else{
        uf.unite(x+n,y);
        uf.unite(x,y+n);
      }

    }else{

      if(uf.is_same(x, y)){
        cout<<"YES"<<endl;
      }else{
        cout<<"NO"<<endl;
      }

    }
  }

  return 0;
}
