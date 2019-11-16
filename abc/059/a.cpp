#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  
  cout<<(char)(s1.at(0)+'A'-'a')<<(char)(s2.at(0)+'A'-'a')<<(char)(s3.at(0)+'A'-'a');
  
  return 0;
}
