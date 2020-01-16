#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,l;
  scanf("%d %d\n",&n, &l);
  vector<int>results(n);
  rep(i,n)results[i]=i+1;

  rep(i, l){
    string s;getline(cin, s);
    rep(j, n-1){
      char c=s[j*2+1];
      if(c=='-')swap(results[j], results[j+1]);
    }
  }

  string s;getline(cin, s);
  rep(i,n) if(s[i*2]=='o') cout<<results[i]<<endl;

  return 0;
}
