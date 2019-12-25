#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<int> a(n);
  int counter=-1;
  rep(i,n){
    cin>>a[i];
    if(a[i]==1 && counter==-1)counter=2;
    if(a[i]==counter)counter++;
  }
  if(counter==-1)cout<<-1;
  else cout<<n-counter+1;

  return 0;
}
