#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

#define MOD 1000000007

using namespace std;
const int nmax=1005;
int memo[nmax][nmax];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int h,w;
int board[nmax][nmax];

int f(int x, int y){
  if(memo[y][x]!=0)return memo[y][x];

  int result=0;
  rep(i,4){
    int tox=x+dx[i];
    int toy=y+dy[i];
    if(tox>=0 && tox<=w-1 && toy>=0 && toy<=h-1&&board[y][x]<board[toy][tox]){
      result += f(tox, toy);
      result %= MOD;
    }
  }
  return memo[y][x]=(result+1)%MOD;
}

int main(){
  cin>>h>>w;
  rep(i,h)rep(j,w)cin>>board[i][j];

  ll ans = 0;
  rep(i,h)rep(j,w){
//cout<<j<<','<<i<<endl;
    ans += f(j, i);
    ans %= MOD;
  }

  cout<<ans<<endl;

  return 0;
}
