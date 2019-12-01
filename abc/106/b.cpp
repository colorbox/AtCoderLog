#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;

  int result=0;
  rep(i,n){
    if((i+1)%2==0)continue;

    int count=0;
    rep(j,i+1){
      if((i+1)%(j+1)==0)count++;
    }
    if(count==8)result++;
//    if(count==8)cout<<i+1<<endl;
  }

  cout<<result;
  return 0;
}
