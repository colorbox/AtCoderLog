#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;
  cin>>s;
  map<char, int> m;
  rep(i, s.size()){
    m[s.at(i)]++;
  }
  char c[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  for(auto cc : c){
    cout<<m[cc];
    if(cc!='F')cout<<' ';
  }
  cout<<endl;
  return 0;
}
