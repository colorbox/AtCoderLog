#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n = 5;
  ll M=3;
  vector<ll> x({1, 2, 8, 4, 9});
  sort(x.begin(), x.end());

  ll l = 0, r = 10;
  while(r-l>1){
    ll m = (l+r)/2;

    ll c = 1, pre=x[0];
    rep(i, n-1){  
      if(pre+m<=x[i+1]){
        cout<<c<<' '<<pre<<endl;
        pre = x[i+1];
        c++;
      }
    }
        cout<<"========"<<endl;
    if(c<M)r=m;
    else l=m;
    cout<<c<<' '<<m<<endl;
    cout<<"---"<<endl;
  }

  cout<<l<<endl;

  return 0;
}
