#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n, nb=0;
  cin>>n;

  ll result=0;
  rep(i, n){
    ll t;
    cin>>t;
    if(t!=0){
      result+=t;
      nb++;
    }
  }
  cout<<ceil((double)result/(double)nb)<<endl;
  
  return 0;
}
