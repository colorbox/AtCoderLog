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
#define INF 1000000000000000LL

using namespace std;

#define MAXN 110000

vector<ll>d1(MAXN, INF), d2(MAXN, INF);
vector<pll> g1[MAXN], g2[MAXN];
int n,m,s,t;

void di(int s, int t, vector<pll> g[], vector<ll>& d){
  priority_queue<pll, vector<pll>, greater<pll>>q;
  d[s]=0;
  q.push({0, s});
  while(q.size()){
    auto now = q.top(); q.pop();
    if( d[now.S]<now.F )continue;
    // cout<<d[now.S]<<' '<<now.F<<endl;
    for(auto nex:g[now.S]){
      // cout<<nex.F<<':'<<nex.S<<endl;
      ll c = nex.F + now.F;
      if(d[nex.S] <= c)continue;
      d[nex.S] = c;
      q.push({c, nex.S});
    }
  }
//  rep(i, n)cout<<d[i]<<' ';cout<<endl;
}

int main(){
  cin>>n>>m>>s>>t;s--,t--;

  rep(i, m){
    int u,v,a,b;cin>>u>>v>>a>>b;u--,v--;
    g1[u].emplace_back(a, v);
    g1[v].emplace_back(a, u);

    g2[u].emplace_back(b, v);
    g2[v].emplace_back(b, u);
  }

  di(s, t, g1, d1);
  di(t, s, g2, d2);

  deque<pll>r;
  rep(i, n){r.push_back({d1[i]+d2[i], i});}
  sort(r.begin(), r.end());

  rep(i, n){
    while(r.front().S<i)r.pop_front();
    cout<<(ll)pow(10LL, 15)-r.front().F<<endl;
  }

  return 0;

  rep(i, n)cout<<d1[i]<<' ';cout<<endl;
  rep(i, n)cout<<d2[i]<<' ';cout<<endl;

  return 0;
}
