#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,m;cin>>n>>m;

  pair<int,int> ab[n];
  rep(i,n){
    int a,b;cin>>a>>b;
    ab[i] = make_pair(a,b);
  }

  pair<int,int> cd[m];
  rep(i,m){
    int c,d;cin>>c>>d;
    cd[i] = make_pair(c,d);
  }

  rep(i,n){
    int d = 1e9;
    int result = 1;
    rep(j,m){
      int td = abs(ab[i].first - cd[j].first) + abs(ab[i].second-cd[j].second);
      if(d>td){
        d=td;
        result = j+1;
      }
    }
    cout<<result<<endl;
  }
  return 0;
}
