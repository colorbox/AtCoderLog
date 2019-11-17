#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

bool atcoder_contain(char s){
  vector<char> a = {'a','t','c','o','d','e','r'};
  return count(a.begin(), a.end(),s)!=0;
}

int main(){
  string s,t;
  cin>>s;
  cin>>t;
  rep(i, s.size()){
    if(!((s[i]=='@' && !atcoder_contain(t[i]) || 
       t[i]=='@' && !atcoder_contain(s[i]) ||
       s[i]==t[i]))){
      cout<<"You will lose";
    }
  }

  cout<<"You can win";
  
  return 0;
}
