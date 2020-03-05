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

int extgcd(int a, int b, int &x, int &y){
  int d = a;
  if(b==0){
    x=1;
    y=0;
  }else{
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
    cout<<x<<' '<<y<<endl;
  }
  return d;
}

int main(){
  ll a;
  ll b;
  a=4,b=11;

  int x,y;
  int d = extgcd(a, b, x, y);

  cout<<x<<' '<<y<<endl;

  return 0;
}
