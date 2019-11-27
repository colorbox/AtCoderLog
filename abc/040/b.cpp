#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;
  cin>>n;
  int result=n;
  rep(i, n){
    int cr = n-(n/(i+1)*(i+1)) + abs(n/(i+1)-(i+1));
    if (cr < result)result=cr;
  }

  cout<<result;

  return 0;
}
