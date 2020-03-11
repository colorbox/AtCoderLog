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

int w,h;
vector<pi> g[31][31];
int d[31][31];

void connect(pi l, pi r){
  g[l.first][l.second].push_back(r);
  g[r.first][r.second].push_back(l);
}

void clear_all(){
  rep(i, 31)rep(j, 31){
    g[i][j].clear();
    d[i][j]=0;
  }
}

int main(){
  while(true){
    cin>>w>>h;
    if(w==0)break;

    rep(y, 2*h-1){
      if(y%2==0){
        rep(x, w-1){
          int wall;cin>>wall;
          if(!wall){
            connect({y/2, x}, {y/2, x+1});
          }
        }
      }else{
        rep(x, w){
          int wall;cin>>wall;
          if(!wall){
            connect({y/2, x}, {y/2+1, x});
          }
        }
      }
    }

    queue< pair<pi, int> > q;
    q.push( {{0,0},1} );
    while( !q.empty() ){
      auto cp = q.front();q.pop();
      auto c = cp.first;
      int y = c.first, x = c.second;
      if(d[y][x]>0)continue;

      int cost = cp.second;
      d[y][x] = cost;
      for(auto p: g[y][x]){
        q.push({p, cost+1});
      }
    }
    cout<<d[h-1][w-1]<<endl;

    clear_all();
  }

  return 0;
}
