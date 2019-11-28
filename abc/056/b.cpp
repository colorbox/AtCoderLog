#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int w,a,b;cin>>w>>a>>b;

  int tmp = max(b-a-w,a-b-w);
  cout<<max(tmp, 0);

  return 0;
}
