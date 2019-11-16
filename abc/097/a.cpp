#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int d;
  vector<int> abc(3);
  cin>>abc[0]>>abc[1]>>abc[2]>>d
  
  sort(abc.begin(), abc.end());
  if(abc[2]-abc[0]<=d){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
  
  return 0;
}
