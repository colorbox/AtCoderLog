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

int gcd(int a, int b){
  if(a==1 || b==1)return 1;
  if (a < b)swap(a,b);
  
  return b ? gcd(b, a % b) : a;
}

int main(){
  ll x1,y1;
  ll x2,y2;

  x1=1;
  y1=11;
  x2=5;
  y2=3;

  int result = gcd(abs(x1-x2), abs(y1-y2))-1;
  if(result<0)result=0;
  cout<<result<<endl;

  return 0;
}
