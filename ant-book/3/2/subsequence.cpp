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
  int n,s;cin>>n>>s;
  vector<int>a(n);
  rep(i, n)cin>>a[i];

  int l=0,r=1;
  int sum=a[0];
  int result=n+1;
  while(l<n && r<=n){
    
    if(sum<s){
      if(r==n)break;
      
      sum+=a[r];
      r++;
    } else {
      result = min(result, r-l);
      cout<<r-l<<':'<<l<<' '<<r<<endl;
      sum-=a[l];
      l++;
    }
  }

  cout<<(result==n+1 ? 0 : result)<<endl;
  cout<<r-l<<':'<<l<<' '<<r<<endl;

  return 0;
}
