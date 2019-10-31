#include<bits/stdc++.h>

using namespace std;

int main(){
  map<string, int> ma, mb;
  array<string, 100> strs;
  int n,m;
  cin>>n;
  for(int i=0;i<n;i++){
    string str;
    cin>>str;
    ma[str]++;
    strs[i]=str;
  }

  cin>>m;
  for(int i=0;i<m;i++){
    string str;
    cin>>str;
    ma[str]--;
  }

  int result = 0;
  for(auto it=ma.begin();it!=ma.end();it++){
    if(result < it->second){
      result = it->second;
    }
  }
  cout<<result;

  return 0;
}
