#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  
  string s;
  cin>>s;

  transform(s.begin(), s.end(), s.begin(), tolower);

  s[0]=toupper(s[0]);
  
  cout<<s<<endl;

  return 0;
}
