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
  vector<int> a(n);
  rep(i, n)cin>>a[i];
  int q;cin>>q;
  vector<int>m(q);
  rep(i, q)cin>>m[i];

  map<int, bool>ans;
  rep(i, pow(2,n)){
    int tmp = 0;
    rep(j, n){
      if((i >> j) & 1)tmp += a[j];
      // cout<<i<<' '<<((i >> j) & 1)<<endl;
    }
    ans[tmp]=true;
  }

  rep(i, q){
    if(ans[m[i]]) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }

  return 0;
}
