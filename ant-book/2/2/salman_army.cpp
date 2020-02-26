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
  int n=6, r=10;
  vector<int> x({1,7,15,20,30,50});
  
  int result=0, lim=-1;
  rep(i, n){
    if(x[i]>lim){
      lim = x[i]+r;
      for(int j=n-1; j>=i; j--){
        if(x[j]<=lim){
          result++;
          lim = x[j]+r;
          cout<<x[j]<<endl;
          break;
        }
      }
    }
  }

  cout<<result<<endl;

  return 0;
}
