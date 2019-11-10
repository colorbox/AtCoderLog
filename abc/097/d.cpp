#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); i++)

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
  int n,m;
  cin>>n>>m;
  vector<int> pp;
  rep(i,n){
    int t;
    cin>>t;
    pp.push_back(t);
  }
  UnionFind uf = UnionFind(n);

  rep(i,m){
    int x,y;
    cin>>x>>y;
    uf.unite(x,y);
  }

  int result=0;
  rep(i, n){
//    cout<<i+1<<' '<<pp[i]<<endl;
    if(uf.is_same(i+1,pp[i])){
      result++;
    }
  }

//  rep(i,n){
//    cout<<pp[i]<<' ';
//  }
//  cout<<endl;

  cout<<result<<endl;

  return 0;
}
