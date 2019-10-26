// copied from https://atcoder.jp/contests/abc110/submissions/8089381

#include<bits/stdc++.h>

using namespace std;

#define MAX_COMB_F 100100 

long long MOD = pow(10,9)+7;
long long comb[MAX_COMB_F][50];

main(){
  long long n, m, temp;
  //n=100000;
  //m=536870912;
  cin>>n>>m;
  vector<long long> p;
  temp=m;

  for(int i=2;i<MAX_COMB_F;i++){
    long long count=0;
    while (temp%i==0){
      temp /= i;
      count++;
    }
    p.push_back(count);
  }

  // for(int i=0;i<MAX_COMB_F;i++){
  //   cout<<p[i]<<' ';
  // }
  // cout<<endl;
  // cout<<endl;
  // cout<<endl;

  if(temp!=1){p.push_back(1);}

  comb[0][0]=1;

  for(int i=1;i<MAX_COMB_F;i++){
    for(int j=0;j<50;j++){

      if(j-1>=0){
        comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
      }else{
        comb[i][j] = comb[i-1][j];
      }
      comb[i][j] %= MOD;
    }
  }

  long long ans = 1;
  for(int i=0;i<p.size();i++){
    long long m;
    m=p[i];
    if(n-1+m>MAX_COMB_F){

      cout<<n<<endl;
      cout<<m<<endl;
      cout<<(n-1+m)<<endl;
    }
    ans *= comb[n-1+m][m];
    ans %= MOD;
  }

  cout << ans << endl;

}
