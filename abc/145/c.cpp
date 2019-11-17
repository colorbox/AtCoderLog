#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

double dist(pair<int, int> l, pair<int, int> r){
  double dx = l.first-r.first;
  double dy = l.second-r.second;
  return pow(dx*dx+dy*dy, 0.5);
}

int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> xy;
  rep(i, n){
    int x,y;
    cin>>x>>y;
    xy.emplace_back(x,y);
  }
  
  vector<int> ar;
  rep(i,n){
    ar.push_back(i);
  }
  
  double sum = 0;

  do {
    rep(i,n-1){
      sum += dist(xy[ar[i]], xy[ar[i+1]]);
    }
  } while( next_permutation(ar.begin(), ar.end()) );
  
  int fac = 1;
  rep(i,n) fac *= (i+1);

  cout<<fixed<<setprecision(6)<<(sum/fac)<<setprecision(6);

  return 0;
}
