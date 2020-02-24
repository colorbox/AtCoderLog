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
  int n=4,r=4;
    vector<tuple<int, int, int>> g = {
    make_tuple(1, 2, 100),
    make_tuple(2, 3, 250),
    make_tuple(2, 4, 200),
    make_tuple(3, 4, 100),
  };

  vector<pi> graph[5001];
  rep(i, g.size()){
    int f = get<0>(g[i]);
    int t = get<1>(g[i]);
    int c = get<2>(g[i]);
    graph[f].emplace_back(c, t);
    graph[t].emplace_back(c, f);
  }

  priority_queue< pi, vector<pi>, greater<pi> > q;
  q.push({0,1});
  ll d[n+1];
  ll d2[n+1];
  rep(i, n)d[i+1] = d2[i+1] = INF;
  d[1]=0;

  while(!q.empty()){
    auto p = q.top();q.pop();
    int from = p.second;
    int from_cost = p.first;

    if(d2[from] < from_cost)continue;

    for(auto p: graph[from]){
      ll to = p.second;
      ll move_cost = p.first;
      ll current_cost = from_cost + move_cost;
      if(d[to] > current_cost){
        swap(current_cost, d[to]);
        q.emplace(d[to], to);
      }
      if(d2[to] > current_cost && current_cost > d[to]){
        d2[to] = current_cost;
        q.emplace(d2[to], to);
      }
    }
  }

  cout<<d[n]<<' '<<d2[n]<<endl;
  rep1(i, n)cout<<d[i]<<' ';cout<<endl;
  rep1(i, n)cout<<d2[i]<<' ';cout<<endl;

  return 0;
}

/*
300 450
0 100 350 300 
200 300 400 450 
*/
