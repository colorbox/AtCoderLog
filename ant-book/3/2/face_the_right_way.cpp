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

#define MAXN 5000

bool cows[MAXN];

int main(){
  int n;cin>>n;
  string s;cin>>s;

  rrep1(i, n){
    rep(i, n)cows[i]=(s[i]=='F');
    rep(i, n)cout<<cows[i];cout<<endl;

    int oc=0;
    for(int j=0; j+i<=n; j++){
      if(cows[j])continue;

      oc++;
      rep(k, i)cows[j+k] = !cows[j+k];
    }

    bool f=true;
    rep(i, n)if(!cows[i])f=false;
    rep(i, n)cout<<cows[i];cout<<endl<<endl;

    if(f)cout<<i<<' '<<oc<<endl;
  }
  

  return 0;
}

//7 BBFBFBB
