#include<bits/stdc++.h>

//#define MOD 1000000007
long long MOD = pow(10,9)+7;


using namespace std;

long long pow2(long long n, long long k){
  if(k==0 || n==1){ return 1; }
  if (k%2==0){
    return ( pow2( (n*n)%MOD, (long long)(k/2)) % MOD );
  }else{
    return (n*pow2(n, k-1)) % MOD;
  }
}

int main(){
  int n, k;
  cin >>n;
  cin >>k;

  long long fac[n+k-1+1];
  long long r_fac[n+k-1+1];

  fac[0]=1;
  for(int i=1;i<=n+k-1;i++){
    fac[i] = fac[i-1]*i%MOD;
//    cout<<i<<' '<<fac[i]<<endl;
  }
//  cout<<endl;

  r_fac[0]=1;
  for(int i=1;i<=n+k-1;i++){
    r_fac[i] = pow2(fac[i], MOD-2)%MOD;
//    cout<<i<<' '<<r_fac[i]<<endl;
  }
//  cout<<endl;

  long long result = ((fac[n+k-1]*r_fac[n-1]%MOD)*r_fac[k]%MOD);
  cout<<result<<endl;

  return 0;
}
