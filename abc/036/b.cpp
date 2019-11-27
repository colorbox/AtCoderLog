#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> ss;
  rep(i,n){
    string t;
    cin>>t;
    ss.push_back(t);
  }

  rep(i,n){
    rep(j,n){
      cout<<ss[n-1-j][i];
    }
    cout<<endl;
  }
  
  return 0;
}
