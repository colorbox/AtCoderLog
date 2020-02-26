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
  vector<pi> c({{1,3},{5,2},{10,1},{50,3},{100,0},{500,2}});
  int a = 620;

  sort(c.rbegin(), c.rend());

  int result = 0;
  int cc = 0;

  for(auto p:c){
    cc=a/p.first;
    if(cc>p.second)cc = p.second;
    result += cc;
    a -= p.first*cc;
  }

  cout<<result<<endl;

  return 0;
}
