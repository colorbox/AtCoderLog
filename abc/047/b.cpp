#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int w,h,n;
  cin>>w>>h>>n;
  int u=h, d=0, l=0, r=w;

  rep(i,n){
    int x,y,a;
    cin>>x>>y>>a;
    if(a==1 && l<x)l=x;
    if(a==2 && r>x)r=x;
    if(a==3 && d<y)d=y;
    if(a==4 && y<u)u=y;
  }

//  cout<<u<<' '<<d<<' '<<l<<' '<<r<<' '<<endl;
  if( u-d<0 || r-l<0){
    cout<<0;
    return 0;
  }
  int result = (u-d)*(r-l);
  cout<<result;

  return 0;
}
