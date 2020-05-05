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
  ll n,x;cin>>n>>x;
  vector<ll> w(n/2);
  rep(i, n/2)cin>>w[i];

  map<ll,ll>nowm, nexm;
  for(auto cw: w){
    nexm = map<ll, ll>(nowm);
    nexm[cw]++;
    for(auto p: nowm) if(p.first+cw<=x)nexm[p.first+cw]+=nowm[p.first];
    swap(nexm, nowm);
//cout<<nowm.size()<<endl;for(auto p: nowm)cout<<p.first<<','<<p.second<<endl;cout<<"---"<<endl;
  }
  map<ll, ll>m1(nowm);

  rep(i, n/2)cin>>w[i];
  if(n%2==1) { ll t; cin>>t; w.push_back(t); }

  nowm.clear(); nexm.clear();
  for(auto cw: w){
    nexm = map<ll, ll>(nowm);
    nexm[cw]++;
    for(auto p: nowm) if(p.first+cw<=x)nexm[p.first+cw]+=nowm[p.first];
    swap(nexm, nowm);
//cout<<nowm.size()<<endl;for(auto p: nowm)cout<<p.first<<','<<p.second<<endl;cout<<"---"<<endl;
  }

  map<ll, ll>m2(nowm);

  ll result=0;
  for(auto p: m1){
    ll c = m2[abs(p.first-x)];
    result += p.second*c;
  }
  for(auto p: m2){
    ll c = m1[abs(p.first-x)];
    result += p.second*c;
  }
  result /= 2;

  for(auto p1: m1)if(p1.first==x)result+=p1.second;
  for(auto p2: m2)if(p2.first==x)result+=p2.second;

  cout<<result<<endl;

  return 0;

  for(auto p1: m1)cout<<p1.first<<','<<p1.second<<' ';cout<<endl;
  for(auto p1: m2)cout<<p1.first<<','<<p1.second<<' ';cout<<endl;

  return 0;
}
