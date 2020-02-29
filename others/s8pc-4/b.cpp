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
  int n,k;cin>>n>>k;
  vector<ll>a(n);
  rep(i, n)cin>>a[i];

  ll result = INF;
  rep(bits, pow(2, n)){
    if(__builtin_popcount(bits)<k)continue;

    vector<ll>ca(a);
    ll tmp=0;
    rrep(i, n){
      if( !(bits>>i&1) )continue;

      ll current_height = ca[n-1-i];
      ll pre_max = 0;
      rep(j, n-1-i)pre_max = max<ll>(pre_max, ca[j]);
      ll alter_height = max<ll>(pre_max+1, current_height);
      ll diff = alter_height - current_height;
      tmp += diff;
      ca[n-1-i] = alter_height;
    }
    result = min<ll>(result, tmp);
  }

  cout<<result<<endl;

  return 0;
}
