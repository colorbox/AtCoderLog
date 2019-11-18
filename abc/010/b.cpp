#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;
  cin>>n;
  
  ll result=0;
  rep(i,n){
    ll t;
    cin>>t;
    while(t%2==0 || t%3==2){
      t--;
      result++;
    }
  }
  
  cout<<result<<endl;
  
  return 0;
}
