// from https://atcoder.jp/contests/code-festival-2017-qualb/submissions/8517446

#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

ll color[110000];
vector<ll> v[110000];

bool dfs(ll x, ll c){
  color[x]=c;
  rep(i, v[x].size()){
    if(color[v[x][i]]==c)return false;
    if(color[v[x][i]]==0 && !dfs(v[x][i], -c) )return false;
  }
  return true;  
}

int main(){
  ll n,m;
  cin>>n>>m;

  rep(i, m){
    ll a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  if(dfs(1,1)){
    ll count=0;
    rep(i, n){ 
      if(color[i+1]==1)count++;
    }
    cout<<count*(n-count)-m;
  }else{
    cout<<n*(n-1)/2-m;
  }

  return 0;
}
