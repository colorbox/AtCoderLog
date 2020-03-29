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

#define MAXN 100001
bool is_prime[MAXN];
bool similar_2017[MAXN];
int cum_count[MAXN];

int main(){
  rep(i, MAXN)is_prime[i]=true;
  is_prime[0]=is_prime[1]=false;
  for(int i=2; i<MAXN; i++){
    for(int j=i*2; j<MAXN; j+=i)is_prime[j]=false;
  }

  rep(i, MAXN)similar_2017[i]=false;
  for(int c=1; c<MAXN; c+=2)similar_2017[c]=(is_prime[c] && is_prime[(c+1)/2]);

  rep1(i, MAXN-1)cum_count[i]=(similar_2017[i] ? 1 : 0)+cum_count[i-1];

  int n;cin>>n;
  rep(i, n){
    int l, r;cin>>l>>r;
    cout<<cum_count[r]-cum_count[l-1]<<endl;
  }

  return 0;

rep(i, 20)cout<<is_prime[i]<<' ';cout<<endl;
rep(i, 20)cout<<similar_2017[i]<<' ';cout<<endl;
rep(i, 20)cout<<cum_count[i]<<' ';cout<<endl;

  return 0;
}
