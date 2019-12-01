#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  vector<int> a(n);
  rep(i,n){
    int t;cin>>a[i];
  }
  sort(a.begin(), a.end());
  cout<<a[a.size()-1]-a[0];

  return 0;
}
