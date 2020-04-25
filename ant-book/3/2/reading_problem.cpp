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
  int n;cin>>n;
  vector<int> a(n);
  rep(i, n)cin>>a[i];
  map<int, int>m;
  rep(i, n)m[a[i]]++;
  int need = m.size();
  map<int, int>c;
  int l, r, result=n+1;
  l=r=0;
  while(l<n && r<n){
    if(c.size()<need){
      c[a[r]]++;
      r++;
    }else{
      c[a[l]]--;
      if(c[a[l]]==0)c.erase(a[l]);
      l++;
    }
    cout<<l<<' '<<r<<':'<<c.size()<<' '<<r-l<<endl;
    if(c.size()==need)result = min(result, r-l);
  }

  cout<<result<<endl;


  return 0;
}
