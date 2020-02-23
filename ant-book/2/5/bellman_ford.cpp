#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n=7;

  vector<tuple<int, int, int>> graph = {
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

    make_tuple(1, 0, 2),
    make_tuple(2, 0, 5),
    make_tuple(2, 1, 4),
    make_tuple(3, 1, 6),
    make_tuple(4, 1, 10),
    make_tuple(3, 2, 2),
    make_tuple(5, 3, 1),
    make_tuple(5, 4, 3),
    make_tuple(6, 4, 5),
    make_tuple(5, 6, 9),
  };

  ll d[n+1];
  rep1(i, n)d[i]=INF;
  d[0]=0;

  bool has_loop = false;
  rep(i, n){
    for(auto p:graph){
      int from = get<0>(p), to = get<1>(p), cost = get<2>(p);

      if(d[from]+cost < d[to]){
        d[to] = d[from]+cost;
      }
// rep(i,n)cout<<d[i]<<' ';cout<<endl;
    }

    // n回目の更新があるなら、負の閉路を持つ
    if(i==n-1)has_loop=true;
  }

  if(has_loop)cout<<-1<<endl;
  else cout<<d[n-1]<<endl;

// rep(i,n)cout<<d[i]<<' ';cout<<endl;

  return 0;
}
