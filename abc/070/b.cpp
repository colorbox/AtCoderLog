#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int a,b,c,d;cin>>a>>b>>c>>d;

  cout<<max(0,min(b,d)-max(a,c));

  return 0;
}
