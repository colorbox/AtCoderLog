#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  rep(i,q){
    int l,r,t;
    cin>>l>>r>>t;
    rep(i, r-l+1){
      a[i+l-1] = t;
    }
  }

  rep(i,n){
    cout<<a[i]<<endl;
  }
  return 0;
}
