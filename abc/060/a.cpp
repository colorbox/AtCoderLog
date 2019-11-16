#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string a,b,c;
  cin>>a>>b>>c;
  
  if(a.back()==b.at(0) && b.back()==c.at(0)){
    cout<<"YES";
  }else{
    cout<<"NO";
  }
  return 0;
}
