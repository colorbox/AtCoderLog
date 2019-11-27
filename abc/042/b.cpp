#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,l;
  cin>>n>>l;
  vector<string> s;
  rep(i,n){
    string t;
    cin>>t;
    s.push_back(t);
  }
  sort(s.begin(),s.end());

  rep(i,n){
    cout<<s[i];
  }
  return 0;
}
