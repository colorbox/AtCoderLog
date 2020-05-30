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
  ll n,W; cin>>n>>W;
  vector<ll>w(n), v(n);
  rep(i, n)cin>>w[i];
  rep(i, n)cin>>v[i];

  vector<pll> f;
  rep(bit, 1LL << n/2){
    ll cw=0,cv=0;
    rep(i, n/2){
      if(bit & 1LL << i){
        cw+=w[i];
        cv+=v[i];
      }
    }
    f.push_back({cw, cv});
  }
  sort(f.begin(), f.end());
  cout<<"---"<<endl;
  rep(i, f.size())cout<<f[i].first<<' '<<f[i].second<<endl;

  int m=0;

  f[m]=f[0];
  rep(i, f.size()){
    if(f[m].first < f[i].first){
      f[++m]=f[i];
    }
    if(f[m].first == f[i].first && f[m].second < f[i].second)f[m]=f[i];
  }
  m++;
  cout<<"---"<<endl;
  rep(i, m)cout<<f[i].first<<' '<<f[i].second<<endl;
  cout<<"---"<<endl;

  ll result = 0;
  rep(bit, 1LL << (n-n/2) ){
    ll cw=0, cv=0;
    rep(i, n-n/2){
      if(bit & 1LL << i){
        cw+=w[i+n/2];
        cv+=v[i+n/2];
      }
    }

    auto eit = f.begin();
    advance(eit, m-1);

    auto it = lower_bound(f.begin(), eit, make_pair(W-cw, INF));

    it--;
    ll av = (*it).second;
    result = max<ll>(result, av + cv);
  }

  cout<<result<<endl;

  return 0;
}

/*

4 5
1 2 3 2
2 3 4 2

*/
