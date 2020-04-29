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
  double n,h,r,t;cin>>n>>h>>r>>t;
  double g = 10.0;

  vector<double> results(n);
  rep(i, (int)n){
    double ct = sqrt(2*h/g);
    int c = t/ct;
    bool up = c%2==1;
    double height;
    if(up){
      height = h-(c*ct+ct-t)*(c*ct+ct-t)*g/2.0;
      // height = h-(c*ct+ct-t)*(c*ct+ct-t)*g/2.0;
      // height = h - (h-(t-ct*c)*(t-ct*c)*g/2.0);
    } else {
      cout<<"#"<<endl;
      height = h-(t-ct*c)*(t-ct*c)*g/2.0;
    }
    results[i]=height;
  }
  sort(results.begin(), results.end());

  rep(i, n)cout<<fixed<<setprecision(12)<<(results[i]+(2*r*i)/100.0)<<endl;

  return 0;
}

/*
1 10 10 100
↓
4.949366116653


2 10 10 100
↓
4.949366116653
5.149366116653

*/
