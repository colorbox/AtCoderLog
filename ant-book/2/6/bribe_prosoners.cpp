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
  // int p=20,q=3;
  // vector<int>a({3, 6, 14});

  // int p=8,q=1;
  // vector<int>a({3});

  int p,q;cin>>p>>q;
  vector<int>a(q);
  rep(i, q)cin>>a[i];

  sort(a.begin(), a.end());

  int result=0;
  int l=0, r=p;
  int al=0, ar=q-1;
  rep(i, q){
    if(a[al]-l > r-a[ar]){
      result += (r-l-1);
      l=a[al]+1;
      al++;
    }else{
      result += (r-l-1);
      r = a[ar]-1;
      ar--;
    }
  }

  cout<<result<<endl;

  return 0;
}
