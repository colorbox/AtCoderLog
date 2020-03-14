#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
// #define INF 536999999
#define INF 1000000000000000LL

using namespace std;

#define MAXM 16

ll dp[2][256];

ll makein(ll n){
  if(n<0)return 0;
  if(n>255)return 255;
  return n;
}

void solve(ll n, ll m){
  ll *now=dp[0];
  ll *nex=dp[1];
  
  rep(i, 256)nex[i]=now[i]=INF;
  now[128]=0;

  vector<ll> c(m);
  rep(i, m)cin>>c[i];

  vector<ll> x(n);
  rep(i, n)cin>>x[i];

  rep(i, n){
    rep(i, 256)nex[i]=INF;

    rep(from, 256)for(auto code: c){
      // cout<<code<<' '<<from<<endl;
      ll coded = makein(from+code);
      ll sq = (coded - x[i])*(coded - x[i]);
      // if(now[from]+sq==0 || nex[coded]==0){
      //   cout<<"!!!!"<<from<<'>'<<coded<<':'<<now[from]+sq<<'('<<now[from]<<' '<<sq<<')'<<nex[coded]<<endl;
      // }
      nex[coded]=min(nex[coded],now[from]+sq);
    }
    swap(nex, now);
    // rep(i, 256){
    //   if(now[i]==INF)continue;
    //   cout<<now[i]<<'('<<i<<')'<<' ';
    // }
    // cout<<endl<<endl;
  }
  ll result = INF;
  rep(i, 256)result = min(result, now[i]);
  cout<<result<<endl;
}

/*
toとfromでm*mのパターンを調べているが、それは間違い、何かが塗りつぶされてしまっている
この場合潰されている情報とはなにか

私のコードでは、toを選ぶ時、自乗差が最小になったときの最小値を出すtoを選んでいる
それを選ぶと同時に、コードのベースとなるnbaseの値も更新している。
base[from]にc[to]を足すことで起点となったスコアにコードブックのコードを足して(toを選んで)いる
この足した後の値coded(base[from]+c[to])と、次のコード前のオリジナルのスコアx[i]との差の自乗を算出している。

差の自乗を算出するまではよい、dp配列のとり方がおかしそう
選び方が最大で16通りしか無い、fromの情報が上書きされる、いや、でも次のループでは前の前の情報なんて必要ないはず。
だって直前の選択にのみ依存しているのだから。
直前の選択にのみ依存していても常に最小値を取ることが良いとは限らない。
差の自乗がその時のTで最小値だったとしても、最小値ではなかった箇所からその次のループでの最小値が出てくるかもしれない。
その可能性を排除して、toをウワがいてしまっているのがだめ、あり得るスコアと
*/

// 上記のだめパターンを炙り出せる入力
/*
5 16
1
2
4
8
16
32
64
128
-1
-2
-4
-8
-16
-32
-64
-128
133
10
124
10
127
*/
int main(){
  while(true){
    ll n,m;cin>>n>>m;
    if(n==0)break;
    solve(n, m);
  }

  return 0;
}
