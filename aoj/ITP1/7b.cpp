#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  while(true){
    int n, x;cin>>n>>x;
    if(n==0 && x==0)break;

    int result = 0;
    rep1(i, n-2){
      for(int j=i+1;j<=n-1; j++){
        for(int k = j+1;k<=n; k++){
          if(i+j+k == x)result++;
        }
      }
    }

    cout<<result<<endl;
  }
  return 0;
}
