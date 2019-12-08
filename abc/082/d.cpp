#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  ll x,y;cin>>x>>y;
  vector<ll> moves, uds, lrs;
  ll ff=0;
  if(s[0]=='F')rep(i,s.size()){
    if(s[i]=='F')ff++;
    else break;
  }

  ll fcount=0;
  rep(i, s.size()-ff){
    int ci=i+ff;
    if(s[ci]=='F')fcount++;
    if(s[ci]=='T'){
      moves.push_back(fcount);
      fcount=0;
    }
  }
  if(fcount!=0)moves.push_back(fcount);

  rep(i,moves.size()){
    if(i%2==0) lrs.push_back(moves[i]);
    else uds.push_back(moves[i]);
  }

  ll lrsum=0, udsum=0;
  rep(i,lrs.size())lrsum+=lrs[i];
  rep(i,uds.size())udsum+=uds[i];

  set<ll> udset;
  udset.insert(0);
  rep(i,uds.size()){
    set<ll> tmpset;
    for(auto p : udset){
      tmpset.insert(p+uds[i]);
      tmpset.insert(p-uds[i]);
    }
    udset = tmpset;
  }

  set<ll>lrset;
  lrset.insert(ff);
  rep(i,lrs.size()){
    set<ll> tmpset;
    for(auto t : lrset){
      tmpset.insert(t+lrs[i]);
      tmpset.insert(t-lrs[i]);
    }
    lrset = tmpset;
  }

  if( udset.find(y)!=udset.end() && lrset.find(x)!=lrset.end() ){
    cout<<"Yes";
  }else{
    cout<<"No";
  }

  return 0;

cout<<endl;
for(auto p : udset)cout<<p<<' ';cout<<endl;
for(auto p : lrset)cout<<p<<' ';cout<<endl;

cout<<ff<<endl;
//rep(i,moves.size())cout<<moves[i]<<' ';cout<<endl;
rep(i,lrs.size())cout<<lrs[i]<<' ';cout<<endl;
rep(i,uds.size())cout<<uds[i]<<' ';cout<<endl;

  return 0;
}
