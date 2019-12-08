#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;cin>>n;
  ll a[n-1],b[n-1];
  rep(i,n-1)cin>>a[i]>>b[i];

  vector<ll> graph[n+1];
  rep(i,n-1){
    graph[ a[i] ].push_back( b[i] );
    graph[ b[i] ].push_back( a[i] );
  }

  ll color_count=0;
  rep(i,n)color_count=max(color_count, (ll)graph[i].size());

  map<pair<ll, ll>, ll> color_log;

  ll color_from_parent[n+1];
  
  queue<ll> q;
  q.push(1);
  bool visited[n+1];
  rep(i,n+1)visited[i]=false;
  visited[1]=true;

  while(!q.empty()){
    int from=q.front();
    q.pop();
    ll color=1;
    for(auto to :graph[from]){
      if(visited[to] || from>to)continue;
      if(!visited[to])q.push(to);
      visited[to]=true;
      if(color_from_parent[from]==color)color++;

      color_log[make_pair(from,to)]=color;
      color_from_parent[to]=color;
      color++;
    }
  }

  cout<<color_count<<endl;
  rep(i,n-1)cout<<color_log[make_pair(a[i],b[i])]<<endl;

  return 0;
}
