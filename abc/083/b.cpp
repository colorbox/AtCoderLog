#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,a,b,result=0;cin>>n>>a>>b;
  rep(i,n+1){
    int t=i%10+i/10%10+i/100%10+i/1000%10+i/10000;
//    if( a<=t && t<=b )cout<<i<<' '<<t<<endl;

    if( a<=t && t<=b )result+=i;
  }

  cout<<result;
  return 0;
}
