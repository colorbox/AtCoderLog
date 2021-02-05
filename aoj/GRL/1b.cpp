#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define F first
#define S second

#define MOD 1000000007
#define INF 1000000000

using namespace std;

#define MAXN 1100

int g[MAXN];

int main(){
  int v,e,r;cin>>v>>e>>r;
  
  rep(i, MAXN)g[i]=INF;
  vector<pair<pi, int>>es(e);
  rep(i, e)cin>>es[i].F.F>>es[i].F.S>>es[i].S;

  g[r]=0;

  rep(j, v*2){
    bool updated = false;
    rep(i, e){
      int from = es[i].F.F;
      int to = es[i].F.S;
      int cost = es[i].S;
      if(g[from]==INF)continue;
      int nc = g[from] + cost;
      if(nc < g[to]){
        g[to] = nc;
        updated=true;
      }
    }
    if(j==v*2-1 && updated){
      cout<<"NEGATIVE CYCLE"<<endl;
      return 0;
    }
  }

  rep(i, v){
    if(g[i]==INF)cout<<"INF"<<endl;
    else cout<<g[i]<<endl;

  }

  return 0;
}
