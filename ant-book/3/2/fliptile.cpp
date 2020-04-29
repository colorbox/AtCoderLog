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
#define MAXNM 15

bool tile[MAXNM][MAXNM];
bool flip[MAXNM][MAXNM];
bool ans[MAXNM][MAXNM];

int dx[5] = {0, 0,  0, 1, -1};
int dy[5] = {0, 1, -1, 0,  0};

int n,m;

void init_flip(){
  rep(i, MAXNM)rep(j, MAXNM) flip[i][j]=0;
}

bool get_flipped_tile(int y, int x){
  int c = tile[y][x] ? 1 : 0;
  rep(i, 5){
    int y2 = y+dy[i], x2 = x+dx[i];
    if(y2>=n || y2<0 || x2>m || x2<0)continue;

    if(flip[y2][x2])c++;
  }
  return (c%2==1);
}

bool check_clear(){
  rep(i, m)rep(j, n)if( get_flipped_tile(i, j) )return false;
  return true;
}

int main(){
  cin>>n>>m;
  rep(i, m)rep(j, n) cin>>tile[i][j];

  int result=-1;
  for(int s=0; s < 1<<n; s++){
    init_flip();

    rep(i, n)if(s<<i & 1)flip[0][i]=true;
    for(int i=1; i<m; i++)rep(j, n){
      if(!get_flipped_tile(i-1, j))continue;

      flip[i][j]=true;
    }

    if( check_clear() ){
      int t=0;
      rep(i, m)rep(j, n)if(flip[i][j])t++;

      if(result<0 || t<result){
        rep(i, m)rep(j, n)ans[i][j]=flip[i][j];
        result=t;
      }
    }else{
      // rep(i, m){
      //   rep(j, n)cout<<flip[i][j]<<' ';
      //   cout<<endl;
      // }
      // cout<<endl;
    }
  }

  if(result<0)cout<<"IMPOSSIBLE"<<endl;
  else{
    cout<<result<<endl;
    rep(i, m){
      rep(j, n)cout<<ans[i][j]<<' ';
      cout<<endl;
    }
  }

  return 0;
}

/*
4 4
1 0 0 1
0 1 1 0
0 1 1 0
1 0 0 1

4 4
1 0 0 1
1 0 0 1
1 0 0 1
1 0 0 1

4 4
1 1 1 1
1 0 0 1
1 0 0 1
1 0 0 1

4 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/
