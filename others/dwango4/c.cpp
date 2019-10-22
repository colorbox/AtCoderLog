//from https://atcoder.jp/contests/dwacon2018-prelims/submissions/4910582

#include <bits/stdc++.h>

using namespace std;

int N, M, a[100], b[100], sa, sb;
long mod = 1e9+7, dp[101][1001];
long memo[101][1001];

long f(int*A, int N, int s){
  if (N<0) {return s==0;}
  if (memo[N][s]) {return memo[N][s];}
  int cnt=1;
  while(N-cnt>=0 && A[N-cnt]==A[N]){ cnt++; }
  
  long now=0;
  for(int i=0;i<=s;i++){
    now = (now+dp[cnt][i]*f(A, N-cnt, s-i))%mod;
  }
  
  return memo[N][s]=now;
}

main(){
  cin>>N>>M;
  for(int i=0; i<101;i++){dp[i][0]=1;}
  for(int i=1; i<101;i++){
    for(int j=1; j<1001;j++){
      dp[i][j]= (dp[i-1][j]+(j<i ? 0 : dp[i][j-i])) % mod;
    }
  }
  
  for(int i=N;i--;){
    cin >> a[i];
    sa+=a[i];
  }

  for(int i=M;i--;){
    cin >> b[i];
    sb+=b[i];
  }
  
  long A=f(a, N-1, sb);
  for(int i=0;i<101;i++){
    for(int j=0;j<1001;j++){
      memo[i][j]=0;
    }
  }
  long B=f(b, M-1, sa);
//  cout<<A<<endl;
//  cout<<B<<endl;
  cout << (A*B)%mod;
}
