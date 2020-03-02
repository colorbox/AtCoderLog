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
  n=3;
  vector<int> v1({1, 2, 3, 4, 5});
  vector<int> v2({1, 0, 0, 1, 1});

  sort(v1.begin(), v1.end());
  sort(v2.rbegin(), v2.rend());

  ll result = 0;
  rep(i, n)result += v1[i]*v2[i];

  cout<<result<<endl;
  
  return 0;
}
