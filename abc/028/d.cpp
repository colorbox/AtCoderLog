#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  double n,k;cin>>n>>k;

  cout<<fixed<<setprecision(12)<<((k-1)*(n-k)*6+3*(n-1)+1)/pow(n,3)<<endl;

  return 0;
}
