#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;
  cin>>s;
  ll n;
  cin>>n;
  rep(i, n){
    ll l, r;
    cin>>l>>r;
    reverse(s.begin()+l-1, s.begin()+r);
  }
  
  cout<<s<<endl;
  return 0;
}
