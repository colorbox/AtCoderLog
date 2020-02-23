#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

bool graph[1001][1001];

int color[1001];

bool dfs(int v, int c){
  color[v] = c;
  rep(to, 1001){
    if(!graph[v][to])continue;
    if(color[to]==c)return false;
    // ここで未着色であることのチェックをしないと無限ループする。
    if(color[to]==0 && !dfs(to, -c))return false;
  }
  return true;
}

int main(){
  // vector<pair<int, int>> sg = {
  //   {0,1},
  //   {1,2},
  //   {2,0},
  // };

  vector<pair<int, int>> sg = {
    {0, 1},
    {1, 2},
    {0, 3},
    {3, 2},
  };

  rep(i, sg.size()){
    int f = sg[i].first;
    int t = sg[i].second;
    graph[f][t] = graph[t][f] = true;
  }

  if(dfs(0, 1)) cout<<"OK"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}
