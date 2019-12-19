#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int tree[51];

int main(){
  int n;cin>>n;
  tree[1]=0;

  int maxi = 1;
  rep(i, n-1){
    cout<<"? 1 "<<i+2<<endl;
    cin>>tree[i+2];
    if(tree[i+2] > tree[maxi])maxi = i+2;
  }
  int result = tree[maxi];
  rep(i, n-1){
    cout<<"? "<<maxi<<' '<<i+2<<endl;
    int len;cin>>len;
    result = max(result, len);
  }

  cout<<"! "<<result<<endl;

  return 0;
}
