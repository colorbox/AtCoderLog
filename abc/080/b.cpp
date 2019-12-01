#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  int x=n;

  int fx = 0;
  while(n!=0){
    fx += n%10;
    n/=10;
  }

  if(x%fx==0){
    cout<<"Yes";
  }else{
    cout<<"No";
  }

  return 0;
}
