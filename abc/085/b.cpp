#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  set<int> dd;
  for(int i=0;i<n;i++){
    int d;
    cin>>d;
    dd.insert(d);
  }
  cout<<dd.size();

  return 0;
}