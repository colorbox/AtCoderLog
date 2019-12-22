#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int choco[18][18];

int main(){
  int n,m,p,q,r;cin>>n>>m>>p>>q>>r;
  rep(i,r){
    int x,y,z;cin>>x>>y>>z;
    choco[x-1][y-1]=z;
  }

  int result = 0;
  rep(c, pow(2,n)){
    if((int) __builtin_popcount(c)>p)continue;
    vector<int> h(m, 0);
    rep(from,n){
      if(1 & c>>from){
        rep(to, m){
          h[to] += choco[from][to];
        }
      }
    }

    sort(h.rbegin(), h.rend());
    int tmp_result = 0;
    rep(i,q)tmp_result += h[i];
    result = max(result, tmp_result);
  }

  cout<<result<<endl;

  return 0;
}
