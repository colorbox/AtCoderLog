#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int d,n;cin>>d>>n;
  if(n==100)n++;//100は100で割り切れるのでD回が1ズレる

  cout<<n*(int)pow(100,d);

  return 0;
}
