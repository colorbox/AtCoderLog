#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;
  cin>>n;

  printf("%02d:%02d:%02d", n/3600, (n/60)%60, n%60);

  return 0;
}
