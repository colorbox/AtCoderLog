#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];

  int absmax_i=0;
  rep(i,n) if( abs(a[i]) > abs(a[absmax_i]) )absmax_i=i;

  cout<<2*n-1<<endl;
  rep(i,n)cout<<absmax_i+1<<' '<<i+1<<endl;
  if(a[absmax_i]>0){
    rep(i,n-1)cout<<i+1<<' '<<i+2<<endl;
  }else{
    rep(i,n-1)cout<<n-i<<' '<<n-(i+1)<<endl;
  }

//rep(i,n)cout<<a[i]<<' ';cout<<endl;

  return 0;
}
