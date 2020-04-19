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

#define MAXN 1000000
bool p[MAXN+1];

int main(){
  int n;cin>>n;
  rep(i, MAXN+1)p[i]=true;
  p[0]=p[1]=false;

  for(int i=2; i<=n; i++){
    for(int j=i*2; j<=n; j+=i)p[j]=false;
  }

  int result=0;
  rep1(i, n)if(p[i])result++;

  cout<<result<<endl;

  return 0;
}
