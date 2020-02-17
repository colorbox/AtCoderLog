#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000000LL

using namespace std;

int main(){
  ll n,k;cin>>n>>k;
  vector<ll>a(n);
  rep(i, n)cin>>a[i];
  sort(a.begin(), a.end());

  ll l = -INF, r = INF;

  while(r-l>1){
    ll x = (l+r)/2;
    ll count = 0;
    rep(i, n){
      if(a[i]>=0){

        ll l=-1,r=n;
        while(r-l>1){
          ll m = (l+r)/2;
          // a[i]*a[m]がx以上だとNG
          if(a[i]*a[m]>=x)r=m; else l=m;
        }
        // OKライン(l以下)の中にいる要素数(0-indexなので+1)
        count += (l+1);

      }else{

        ll l=-1,r=n;
        while(r-l>1){
          ll m = (l+r)/2;
          // OK:NGの領域が反転する。
          // a[i]*a[m]<xだとOK、mから見て左の領域から境界値を探す。
          if(a[i]*a[m]<x)r=m; else l=m;
        }
        // OKライン(r以上)の中にいる要素数、rの範囲は1~nなので調整の必要はない。
        // n=5でOKが一つもない時、rは5になる。これは0-indexで考えると配列の外だが、n-rで考えると0になり正しい・
        // また、同様にOKが一だけの時、rは4になる。これは0-indexで考えると配列最終要素だがn-r=1でこれまた正しい。
        count += (n-r);

      }
      if(a[i]*a[i]<x)count--;
    }

    if(count/2>=k)r=x;
    else l=x;

  }

  // lとr、lがOK要素の最終、rがNG要素の最初という具合に境界線を挟んでいる。
  cout<<l;

  return 0;
}
