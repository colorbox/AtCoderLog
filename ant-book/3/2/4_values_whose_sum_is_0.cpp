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
  int n;cin>>n;
  vector<ll>a(n), b(n), c(n), d(n);
  rep(i, n)cin>>a[i];
  rep(i, n)cin>>b[i];
  rep(i, n)cin>>c[i];
  rep(i, n)cin>>d[i];

  map<ll, ll>ab, cd;
  for(auto l:a)for(auto r:b)ab[l+r]++;
  for(auto l:c)for(auto r:d)cd[l+r]++;

  // for(auto l:a)for(auto r:b)cout<<l+r<<' ';cout<<endl;
  // for(auto l:c)for(auto r:d)cout<<l+r<<' ';cout<<endl;

  ll result=0;
  for(auto p1: ab)for(auto p2:cd){
    // cout<<p1.first+p2.first<<endl;
    if(p1.first+p2.first==0)result += p1.second*p2.second;
  }

  cout<<result<<endl; 
  
  return 0;
}

/*
6
-45 -41 -36 -36 26 -32
22 -27 53 30 -38 -54
42 56 -37 -75 -10 -6
-16 30 77 -46 62 45
*/
