#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAX_LEN 50
int board[MAX_LEN][MAX_LEN];
bool used[MAX_LEN][MAX_LEN];
int w,h;

bool isin(int x, int y){
  return (x>=0 && x<w && y>=0 && y<h);
}

void dfs(int x, int y){
  if( !isin(x, y) )return;
  if(used[y][x])return;
  if(board[y][x]==0)return;
  used[y][x]=true;

  dfs(x-1, y);
  dfs(x+1, y);
  dfs(x, y-1);
  dfs(x, y+1);

  dfs(x-1, y-1);
  dfs(x-1, y+1);
  dfs(x+1, y-1);
  dfs(x+1, y+1);
}

int main(){
  while(true){
    cin>>w>>h;
    if(w==0 && h==0)break;
    rep(i, MAX_LEN)rep(j, MAX_LEN){
      board[i][j]=0;
      used[i][j]=false;
    }

    rep(i, h)rep(j, w)cin>>board[i][j];

    int result=0;
    rep(i, h)rep(j, w){
      if(board[i][j]==1 && !used[i][j])result++;
      dfs(j, i);
    }

    // rep(i, h){
    //   rep(j, w)cout<<board[i][j];
    //   cout<<endl;
    // }

    cout<<result<<endl;
  }
  return 0;
}
