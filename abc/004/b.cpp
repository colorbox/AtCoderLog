#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  vector<vector<string>> board;
  
  rep(i, 4){
    vector<string> v;
    rep(j,4){
      string t;
      cin>>t;
      v.push_back(t);
    }
    board.push_back(v);
  }
  
  rep(i, 4){
    rep(j,4){
      cout<<board[3-i][3-j]<<' ';
    }
    cout<<endl;
  }

  return 0;

}
