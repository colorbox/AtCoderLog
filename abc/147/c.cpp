#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<pair<int, int> > sayings[n+1];

  rep(i,n){
    int a;cin>>a;
    rep(j,a){
      int x,y;cin>>x>>y;
      sayings[i].emplace_back(x, y);
    }
  }

  int result=0;
  rep(bits, pow(2,n)){
    bool flag=true;
    rep(i,n){
      if( !(bits>>i & 1) ) continue;

      rep(j, sayings[i].size()){
        int target = sayings[i][j].first;
        if(sayings[i][j].second != bits>>target & 1){
          flag=false;
        }
//cout<<sayings[i][j].second <<' '<< (bits>>target & 1)<<endl;
      }
    }

//cout<<flag<<' '<<bits<<endl<<endl;

    if(flag)result=max(result,  (int)__builtin_popcount(bits));
  }

  cout<<result;

  return 0;
}
