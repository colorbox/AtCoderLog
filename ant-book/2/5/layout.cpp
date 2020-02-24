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
  int n=4,ml=2,md=1;
  int al[] = {1,2};
  int bl[] = {3,4};
  int dl[] = {10,20};
  int ad[] = {2};
  int bd[] = {3};
  int dd[] = {3};

  vector<pair<int, pi>> edges;
  rep(i, n)edges.emplace_back(0, make_pair(i+1, i));
  rep(i, ml)edges.emplace_back(dl[i], make_pair(al[i], bl[i]));
  rep(i, md)edges.emplace_back(-dd[i], make_pair(bd[i], ad[i]));

  ll d[n+1];
  rep1(i, n)d[i]=INF;
  d[1]=0;
  rep(i, n){
    for(auto p: edges){
      int cost = p.first;
      auto from_to = p.second;
      int from = from_to.first;
      int to = from_to.second;
      if(d[to]>d[from]+cost){
        d[to]=d[from]+cost;
      }
    }
  }

  if(d[1]<0) cout<<-1<<endl;
  else if(d[n]==INF) cout<<-2<<endl;
  else cout<<d[n]<<endl;
  
  rep1(i, n)cout<<d[i]<<' ';cout<<endl;
  for(auto p:edges)cout<<p.first<<'('<<p.second.first<<','<<p.second.second<<')'<<endl;

  return 0;
}
