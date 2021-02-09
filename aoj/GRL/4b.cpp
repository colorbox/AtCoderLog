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

int main(){
  int v,e;cin>>v>>e;
  vector<pi>ee(e);
  rep(i, e)cin>>ee[i].F>>ee[i].S;

  vector<int>r, o[v];
  queue<int>z;
  vector<int>c(v);
  rep(i, e)c[ee[i].S]++;
  rep(i, e)o[ee[i].F].push_back(ee[i].S);
  rep(i, v)if(c[i]==0)z.push(i);

  while(z.size()){
    int cc = z.front();
    r.push_back(cc);
    z.pop();

    for(auto nex:o[cc]){
      c[nex]--;
      if(c[nex]==0)z.push(nex);
    }
  }

  for(auto rr:r)cout<<rr<<endl;

  return 0;
}
