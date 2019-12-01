#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int a,b,c;cin>>a>>b>>c;
  int k;cin>>k;

  int tmax = max(a,max(b,c));
  int result=tmax;
  rep(i,k)result *= 2;
  result += (a+b+c-tmax);
  cout<<result;

  return 0;
}
