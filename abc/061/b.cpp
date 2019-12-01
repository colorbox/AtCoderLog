#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,m;cin>>n>>m;

  map<int, int> mm;
  rep(i,m){
    int a,b;cin>>a>>b;
    mm[a]++;
    mm[b]++;
  }

  rep(i,n){
    cout<<mm[i+1]<<endl;
  }
  return 0;
}
