#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

ll d(ll n){
  
}

int main(){
  ll a,b,x;
  cin>>a>>b>>x;
  
  if(a+b>x){
    cout<<0;
    return 0;
  }
  
  ll min,max,mid;
  min=1;
  max=1000000000;
  
  while(max-min>1){
//    cout<<min<<' '<<max<<endl;
    mid=(min+max)/2;
    if((a*mid+b*to_string(mid).length()) <= x ){
      min=mid;
    }else{
      max=mid;
    }
  }

  ll result=min;
  if((a*max+b*to_string(max).length()) <= x ) result=max;
  
  if(result>1000000000) result = 1000000000;
  
  cout<<result;
  
  return 0;
}
