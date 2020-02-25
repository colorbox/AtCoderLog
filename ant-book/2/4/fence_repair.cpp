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

  priority_queue<int, vector<int>, greater<int>> q;
  rep(i,n)q.push(l[i]);
  int result = 0;
  rep(i, n-1){
    int l1 = q.top();q.pop();
    int l2 = q.top();q.pop();
    result += l1 + l2;
    q.push(l1 + l2);
    cout<<result<<endl;
  }

  cout<<result<<endl;

  return 0;
}
