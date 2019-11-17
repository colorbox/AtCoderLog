#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long
#define MOD 10007

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> tri;
  if(n==1 || n==2){
    cout<<0<<endl;
    return 0;
  }
  
  tri.push_back(0);
  tri.push_back(0);
  tri.push_back(1);
  int result = 1;
  rep(i, n){
    int t = (i+3);
    tri.push_back((tri[t-3]+tri[t-2]+tri[t-1])%MOD);
  }
  
  cout<<tri[n-1]<<endl;

  return 0;

}
