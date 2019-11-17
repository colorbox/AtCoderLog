#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;
  cin>>n;
  
  vector<int> t;
  
  rep(i, n){
    int tmp;
    cin>>tmp;
    t.emplace_back(tmp);
  }
  sort(t.begin(), t.end());
  cout<<t[0]<<endl;

  return 0;

}
