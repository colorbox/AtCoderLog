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

#define MAX_NODE 101

int begin_times[MAX_NODE];
int end_times[MAX_NODE];
int c_time=0;
queue<int> g[MAX_NODE];

void dfs(int f){
  if(begin_times[f]>0)return;
  c_time++;
  begin_times[f]=c_time;
  while( !g[f].empty() ){
    int to = g[f].front();
    g[f].pop();
    if(end_times[to]>0)continue;
    dfs(to);
  }
  c_time++;
  end_times[f]=c_time;
}

int main(){
  int n;cin>>n;
  rep(i, n){
    int from;
    int count;
    cin>>from>>count;
    rep(j, count){
      int t;cin>>t;
      g[from].push(t);
    }
  }

  rep1(i, n)dfs(i);

  rep1(i, n){
    cout<<i<<' '<<begin_times[i]<<' '<<end_times[i]<<endl;
  }

  return 0;
}
