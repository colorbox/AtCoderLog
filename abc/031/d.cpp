#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

bool checker(vector<int> counter, map<string, string> m){
  for(auto p : m){
    string k=p.first;
    int len_c = 0;

    rep(i, k.size()) len_c+=counter[(int)(k[i]-'0')];

    if(len_c!=p.second.size())return false;
  }
  return true;
}

vector<int> dfs(int limit, int current, vector<int> counter, map<string, string> m){
  if(current>limit)return counter;
  rep(i, 3){
    counter[current]=i+1;
    auto tmp = dfs(limit, current+1, counter ,m);
    if(checker(tmp, m))return tmp;
  }
  return counter;
}

int main(){
  int k,n;cin>>k>>n;
  map<string, string> m;
  rep(i,n){
    string ky,v;cin>>ky>>v;
    m[ky]=v;
  }
  vector<int> c(k+1, 1);
  auto lengths = dfs(k, 1, c, m);

  map<int, string> result;
  for(auto p:m){
    string k=p.first;
    string str=p.second;
    int from=0;
    rep(j, k.size()){
      int result_key = (int)(k[j]-'0');
      result[result_key] = str.substr(from, lengths[result_key]);
      from += lengths[result_key];
    }
  }

  rep(i, k)cout<<result[i+1]<<endl;

  return 0;
}
