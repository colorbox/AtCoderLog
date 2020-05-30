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

int main(){
  int n;
  ll w,h;
  cin>>w>>h>>n;

  vector<ll> x1(n),y1(n),x2(n),y2(n);
  rep(i, n)cin>>x1[i];
  rep(i, n)cin>>x2[i];
  rep(i, n)cin>>y1[i];
  rep(i, n)cin>>y2[i];

  vector<ll> x_all;
  for(auto c:x1){
    for(int i=-1; i<=1; i++)if(1<=c+i && c+i <= w)x_all.push_back(c+i);
  }
  for(auto c:x2){
    for(int i=-1; i<=1; i++)if(1<=c+i && c+i <= w)x_all.push_back(c+i);
  }
  sort(x_all.begin(), x_all.end());

  cout<<x_all.size()<<':';
  x_all.erase( unique(x_all.begin(), x_all.end()) , x_all.end());
  cout<<x_all.size()<<endl;

  rep(i, n){
    x1[i] = lower_bound(x_all.begin(), x_all.end(), x1[i])-x_all.begin();
    x2[i] = lower_bound(x_all.begin(), x_all.end(), x2[i])-x_all.begin();
  }
  w = x_all.size();

  vector<ll> y_all;
  for(auto c:y1){
    for(int i=-1; i<=1; i++)if(1<=c+i && c+i <= h)y_all.push_back(c+i);
  }
  for(auto c:y2){
    for(int i=-1; i<=1; i++)if(1<=c+i && c+i <= h)y_all.push_back(c+i);
  }
  sort(y_all.begin(), y_all.end());

  cout<<y_all.size()<<':';
  y_all.erase( unique(y_all.begin(), y_all.end()) , y_all.end());
  cout<<y_all.size()<<endl;
  cout<<endl<<"----"<<endl;
  for(auto c:x_all)cout<<c<<' ';cout<<endl;
  for(auto c:y_all)cout<<c<<' ';cout<<endl;
  cout<<"----"<<endl;
  

  rep(i, n){
    y1[i] = lower_bound(y_all.begin(), y_all.end(), y1[i])-y_all.begin();
    y2[i] = lower_bound(y_all.begin(), y_all.end(), y2[i])-y_all.begin();
  }
  h = y_all.size();

  cout<<"----"<<endl;
  cout<<h<<','<<w<<endl;
  rep(i, n)cout<<x1[i]<<' ';cout<<endl;
  rep(i, n)cout<<x2[i]<<' ';cout<<endl;
  rep(i, n)cout<<y1[i]<<' ';cout<<endl;
  rep(i, n)cout<<y2[i]<<' ';cout<<endl;
  cout<<"----"<<endl;

  // 初期化
  bool b[h][w];
  rep(x, w)rep(y, h)b[y][x]=false;

  // 既存の道をマーキング
  rep(i, n){
    for(int x=x1[i]; x<=x2[i]; x++){
      for(int y=y1[i]; y<=y2[i]; y++){
        // cout<<y<<','<<x<<' ';
        b[y][x]=true;
      }
    }
    
  rep(y, h){
    rep(x, w)cout<<(b[y][x]?"■":"□");cout<<endl;
  }
  cout<<"---"<<endl;


  }

  rep(y, h){
    rep(x, w)cout<<(b[y][x]?"■":"□");cout<<endl;
  }
  cout<<"---"<<endl;


  ll result=0;  
  rep(x, w)rep(y, h){
    if(b[y][x])continue;
    result++;

    // BFS
    queue<pll> q;
    q.push({y, x});

    while(q.size()){
      auto t = q.front();q.pop();
      auto ty = t.first, tx = t.second;
      if(b[ty][tx])continue;
      b[ty][tx]=true;

      int dx[4] = {0, 1, 0,-1};
      int dy[4] = {1, 0,-1, 0};

      rep(i, 4){
        ll ny = ty + dy[i];
        ll nx = tx + dx[i];
        if(ny>=0 && ny<h && nx>=0 && nx<w)q.push({ny, nx});
      }
    }
  }

  cout<<result<<endl;

  return 0;
}

/*

10 10 5
1 1 4 9 10
6 10 4 9 10
4 8 1 1 6
4 8 10 5 10

*/
