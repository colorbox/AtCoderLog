#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<int> d(n);
  rep(i,n)cin>>d[i];
  sort(d.begin(), d.end());
  auto last = unique(d.begin(), d.end());
  d.erase(last, d.end());
//rep(i, d.size())cout<<d[i]<<' ';
cout<<endl;
  cout<<d.size();
  return 0;
}
