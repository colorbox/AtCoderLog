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

int main(){
  int n=7;

  vector<tuple<int, int, int>> g = {
    make_tuple(0, 1, 2),
    make_tuple(0, 2, 5),
    make_tuple(1, 2, 4),
    make_tuple(1, 3, 6),
    make_tuple(1, 4, 10),
    make_tuple(2, 3, 2),
    make_tuple(3, 5, 1),
    make_tuple(4, 5, 3),
    make_tuple(4, 6, 5),
    make_tuple(6, 5, 9),
  };

  ll graph[1001][1001];
  rep(i, 1001)rep(j, 1001)graph[i][j]=INF;
  for(auto p: g){
    ll f = get<0>(p);
    ll t = get<1>(p);
    ll c = get<2>(p);
    graph[t][f] = graph[f][t] = c;
  }
  graph[0][0]=0;

  rep(k, n)rep(i, n)rep(j, n){
    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
  }

  rep(i, n){
    rep(j, n)cout<<graph[i][j]<<' ';
    cout<<endl;
  }

  return 0;
}
