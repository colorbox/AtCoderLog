#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

template<class Abel> struct WeightedUnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    WeightedUnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n+1, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

int main(){
  int n, m;
  cin>>n>>m;
  
  WeightedUnionFind<int> wuf(n);
  
  rep(i,m){
    int l,r,d;
    cin>>l>>r>>d;
    if(!wuf.issame(l, r)){
      wuf.merge(l, r, d);
    }else{
      if(d != wuf.diff(l,r)){
        cout<<"No";
        return 0;
      }
    }
  }
  cout<<"Yes";

  return 0;
}
