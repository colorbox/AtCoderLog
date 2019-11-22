#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll a,b;
  cin>>a>>b;

  ll res = 10;
  if(abs(a-b)<res)res = abs(a-b);
  if(abs(b-a)<res)res = abs(b-a);
  if(abs(a+10-b)<res)res = abs(a+10-b);
  if(abs(b+10-a)<res)res = abs(b+10-a);

  cout<<res<<endl;

  return 0;
}
