//From: https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/8085133
//From: https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/2874428

#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

struct PartiallyPersistentUnionFind {
  vector<int> par, rank, time;

  PartiallyPersistentUnionFind(int n){
    par.resize(n+1);
    fill(par.begin(), par.end(), -1);
    rank.resize(n+1);
    time.resize(n+1);
    fill(time.begin(), time.end(), numeric_limits<int>::max());
  }

  int root(int x, int t){
    if(time[x]>t){
      return x;
    }else{
      return root(par[x], t);
    }
  }

  void unite(int x, int y, int t){
    int rx=root(x, t);
    int ry=root(y, t);

    if(rx!=ry){
      if(rank[rx] >= rank[ry]){
        par[ry]=rx;
        time[ry]=t;

        if(rank[rx]==rank[ry]){
          rank[rx] += 1;          
        }
      }else{
        par[rx] = ry;
        time[rx]=t;
      }
    }
  }

  bool is_same(int x, int y, int t){
    return root(x, t)==root(y, t);
  }
};


int main(){
  int n,m,q,t=1;
  cin>>n>>m;

  PartiallyPersistentUnionFind ppuf(n);

  rep(i,m){
    int a,b;
    cin>>a>>b;
    ppuf.unite(a,b,t++);
  }

  cin>>q;
  
  rep(i,q){
    int x,y;
    cin>>x>>y;
    int ng=0, ok=m+1;
    while(ok-ng>1){
      int mid=(ok+ng)/2;
      if(ppuf.is_same(x, y, mid)){
        ok=mid;
      }else{
        ng=mid;
      }
    }
    cout<<(ok==m+1?-1:ok)<<endl;
  }
  
  return 0;
}
