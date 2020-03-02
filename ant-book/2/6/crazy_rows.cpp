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
  int n;n=4;
  vector<string> ss({
    "0010",
    "0100",
    "0100",
    "1000",
  });

  // int n;n=2;
  // vector<string> ss({
  //   "10",
  //   "01",
  // });

  vector<int>nums(n);
  rep(i, n){
    rep(j, n){
      if(ss[i][j]!='0')nums[i]=j+1;
    }
  }

  rep(i, n)cout<<nums[i]<<' ';cout<<endl;

  int result=0;
  rep(i, n){
    int pos;
    for(pos=i; pos<n; pos++)if(nums[pos]<=i+1)break;

    rep(j, pos-i){
      swap(nums[pos-j], nums[pos-1-j]);
      result++;
      rep(k, n)cout<<nums[k]<<' ';cout<<endl;
    }
    cout<<"-"<<endl;
  }

  cout<<result<<endl;

  return 0;
}
