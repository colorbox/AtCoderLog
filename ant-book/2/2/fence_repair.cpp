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
  int n=3;
  vector<int> l({8, 5, 8});

  sort(l.rbegin(), l.rend());
  int result = 0, len;
  rep(i, n)len += l[i];

  rep(i, n-1){
    result += l[i] + len - l[i];
    len -= l[i];
  }

  cout<<result<<endl;

  return 0;
}
