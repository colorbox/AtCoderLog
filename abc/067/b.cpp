#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,k;cin>>n>>k;

  priority_queue<int, vector<int>, greater<int>> q;
  rep(i,n){
    int t;cin>>t;
    q.push(t);
  }
  rep(i,n-k)q.pop();
  int result=0;
  rep(i,k){
    result += q.top();
    q.pop();
  }

  cout<<result;
  return 0;
}
