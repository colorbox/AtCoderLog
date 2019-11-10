#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

string replace(string target, string finder, string replacement){
  string result=string(target);
  
  cout<<result.find(finder)<<endl;

  string::size_type pos=0;

  pos = result.find(finder, pos);
  while(pos != string::npos){
    result.replace(pos, finder.length(), replacement);
    pos = result.find(finder);
  }

  return result;
}

int main(){
  string s;
  cin>>s;

  cout<<replace(s, ",", " ");

  return 0;
}
