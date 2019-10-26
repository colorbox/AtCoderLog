#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX_M_SIZE 100100

long long fac[MAX_M_SIZE];

long long powmod(long long x, long long n){
  if(n==0 || x==1){return 1;}

  if(n%2==0){
    return powmod(x*x%MOD, n/2)%MOD;
  }else{
    return x*powmod(x*x%MOD, (n-1)/2)%MOD;
  }
}

long long nCk(long long n, long long k){
  long long under = (powmod(fac[n-k], MOD-2)*powmod(fac[k], MOD-2))%MOD;
  // cout<<n<<"C"<<k<<' '<<fac[n]<<' '<<under<<"|"<<fac[n-k]<<' '<<powmod(fac[n-k], MOD-2)<<' '<<fac[k]<<' '<<powmod(fac[k], MOD-2)<<endl;
  return (fac[n]*under)%MOD;
}

vector<pair<long long, long long>> prime_factorize(long long n){
  vector<pair<long long, long long>> res;
  for(long long i=2;i*i<=n;i++){
    if(n%i!=0){continue;}
    int count=0;
    while(n%i==0){
      count++;
      n /= i;
    }
    res.push_back(make_pair(i, count));
  }
  if(n!=1){ res.push_back(make_pair(n, 1)); }

  return res;
}

int main(){
  fac[0]=1;

  for(int i=1;i<MAX_M_SIZE;i++){
    fac[i] = fac[i-1]*i%MOD;
  }

  long long n, m;
  cin >>n>>m;

  long long temp=n;
  vector<long long> p;
  p.push_back(0);
  p.push_back(0);

  auto vec = prime_factorize(abs(n));

  long long ans=1;
  for(auto pa : vec){
    int k = pa.second;
    long long tmp = nCk(m+k-1, k);
    ans = (tmp * ans) % MOD;
  }

  long long d = 0;
  if(n<0){
    for(int i=1;i<=m;i+=2){
      d += nCk(m, i);
      d %= MOD;
    }
  }else{
    for(int i=0;i<=m;i+=2){
      d += nCk(m, i);
      d %= MOD;
    }
  }

  // cout << ans <<endl;
  // cout << d <<endl;

  cout << (ans*d)%MOD <<endl;

  return 0;
}
