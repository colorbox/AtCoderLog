#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string x;
  cin>>x;
  
  string result="YES";
  rep(i, x.size()){
    if( !(x[i]=='c' && i+1<x.size() && x[i+1]=='h' || i-1>=0 && x[i-1]=='c' && x[i]=='h' || x[i]=='o' || x[i]=='k' || x[i]=='u') ){
      result="NO";
    }
  }
  
  cout<<result<<endl;
  
  return 0;
}
