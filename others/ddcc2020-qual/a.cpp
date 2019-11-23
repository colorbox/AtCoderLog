#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll x,y;
  cin>>x>>y;
  
  if(x==1 && y==1){
    cout<<1000000;
    return 0;
  }
  ll money = 0;
  if(x==1)money+= 300000;
  if(x==2)money+= 200000;
  if(x==3)money+= 100000;
  if(y==1)money+= 300000;
  if(y==2)money+= 200000;
  if(y==3)money+= 100000;

  cout<<money;
  return 0;
}
