#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  n %= 12;
  
  double md = m*6.0;
  double nd = 30*((double)m/60.0+n);
  
  double result = abs(md-nd);
  if(result > 360-result)result = 360-result;

  cout<<result<<endl;

//  cout<<nd<<' '<<md;
  return 0;
}
