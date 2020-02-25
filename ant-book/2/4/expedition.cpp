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
  int n=4, l=25, p=10;
  int a[] = {10, 14, 20, 21};
  int b[] = {10, 5, 2, 4};

  int c = p, result=0;
  priority_queue<int> q;
  while(l>c){
    rep(i, n)if(a[i]<=c){
      q.push(b[i]);
      b[i]=0;
    }
    if(q.empty())break;
    if(c<l && q.size()>0){
      c += q.top();
      q.pop();
      result++;
    }
    cout<<c<<endl;
  }

  if(c>=l)cout<<result<<endl;
  else cout<<-1<<endl;


  return 0;
}
