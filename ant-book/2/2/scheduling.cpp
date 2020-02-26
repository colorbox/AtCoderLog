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
  int n=5;
  vector<pi> st({
    {1,3},
    {2,5},
    {4,7},
    {6,9},
    {8,10},
  });

  rep(i, n) swap(st[i].first, st[i].second);
  sort(st.begin(), st.end());
  int c = 0, result=0;
  for(auto p:st){
    if(c<p.second){
      result++;
      c=p.first;
      cout<<p.second<<' '<<p.first<<endl;
    }
  }

  cout<<result<<endl;

  return 0;
}
