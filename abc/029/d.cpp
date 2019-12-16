#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;cin>>n;
  ll result=0;
  rep(i,9){
    ll c=pow(10, i+1);
    result+=(n/c)*(c/10);
    if(i==0){
      if(n%c>=1) result++;
    }else{
      if(n%c>=2*c/10-1) result+=c/10;
      else if(n%c>=c/10-1) result+=n%c-(c/10-1);
    }
  }

  cout<<result<<endl;

  return 0;
}
