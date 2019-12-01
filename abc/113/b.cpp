#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,t,a;cin>>n>>t>>a;

  double diff;cin>>diff;
  diff = abs(a-(t-diff*0.006));
  int result=1;

  rep(i,n-1){
    double tt;cin>>tt;
    double td=abs(a-(t-tt*0.006));
    if(td<diff){
      result=i+2;
      diff=td;
    }
  }

  cout<<result;

  return 0;
}
