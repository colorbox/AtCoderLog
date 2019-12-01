#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int h,w;cin>>h>>w;
  vector<string> ss;
  rep(i,h){
    string t;cin>>t;
    ss.push_back(t);
  }

  rep(i,h){
    rep(j,w){
      if(ss[i][j]=='#'){
        cout<<'#';
        continue;
      }
      int result=0;
      if(i-1>=0 && j-1>=0 && ss[i-1][j-1]=='#')result++;
      if(i-1>=0 && ss[i-1][j]=='#')result++;
      if(i-1>=0 && j+1<w && ss[i-1][j+1]=='#')result++;
      if(j+1<w && ss[i][j+1]=='#')result++;
      if(i+1<h && j+1<w && ss[i+1][j+1]=='#')result++;
      if(i+1<h && ss[i+1][j]=='#')result++;
      if(i+1<h && j-1>=0 && ss[i+1][j-1]=='#')result++;
      if(j-1>=0 && ss[i][j-1]=='#')result++;
      cout<<result;
    }
    cout<<endl;
  }
  

  return 0;
}
