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

bool b[8][8];

bool isin(int n){
  return n>=0 && n<8;
}

void put_queen(int x, int y){
  b[y][x]=true;
  rep(i, 8)b[i][x]=true;
  rep(i, 8)b[y][i]=true;

  rep(i, 16){
    if( !(isin(y+i-8) && isin(x+i-8)) )continue;
    b[y+i-8][x+i-8] = true;
  }

  rep(i, 16){
    if( !(isin(y-i+8) && isin(x+i-8)) )continue;
    b[y-i+8][x+i-8] = true;
  }
}

int main(){
  int n;cin>>n;
  vector<int> x(n), y(n);
  rep(i, n)cin>>y[i]>>x[i];

  vector<int> q;
  rep(i, 8)q.push_back(i);

  do {
    rep(i, 8)rep(j, 8)b[i][j]=false;
    
    bool f = true;
    rep(i, 8){
      if(b[i][q[i]]){f=false; break;}

      put_queen(q[i], i);
    }

    if(!f)continue;

    int initial_q_c=0;
    rep(i, n){
      rep(j, 8){
        if(j==y[i] && q[j]==x[i])initial_q_c++;
      }
    }

    if(initial_q_c==n)break;

  }while(next_permutation(q.begin(), q.end()));

  map<pi, bool> m;
  rep(i, 8) m[make_pair(i, q[i])] = true;

  rep(i, 8){
    rep(j, 8){
      if(m[make_pair(i, j)])cout<<'Q';
      else cout<<'.';
    }
    cout<<endl;
  }

  // rep(i, 8)cout<<q[i]<<' ';cout<<endl;

  return 0;
}

/*

# # # Q # . . #
Q # # # # # # #
. # # # Q # # .
# . # # # # # Q
. # . # # Q # #
. . Q # # # # #
# # # # # # Q #
# Q . # # # # #

*/
