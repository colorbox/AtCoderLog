#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int a,b;cin>>a>>b;

  int sum = stoi(to_string(a)+to_string(b));
  int t = (int)pow(sum, 0.5);
  
  if(pow(t,2)==sum){
    cout<<"Yes";
  }else{
    cout<<"No";
  }


  return 0;
}
