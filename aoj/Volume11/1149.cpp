#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll> 

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int n,w,h;

void solve(){
  vector<pi> c(n);
  rep(i, n)cin>>c[i].first>>c[i].second;
  vector<pi> cakes;
  cakes.push_back({w, h});
  rep(i, n){
    int p = c[i].first-1;
    int s = c[i].second;
    int cw = cakes[p].first;
    int ch = cakes[p].second;

    // rep(i, cakes.size()) cout<<cakes[i].first<<','<<cakes[i].second<<' ';

    cakes.erase(cakes.begin()+p);

    // cout<<endl;
    // cout<<i<<'|'<<cw<<','<<ch<<':'<<p<<' '<<s<<endl;
    // cout<<endl;

    s %= (cw + ch)*2;
    pi c1,c2;
    if(s<cw){
      c1 = {s, ch};
      c2 = {cw-s, ch};
    }else if((cw+ch < s && s < cw+ch+cw)){
      c1 = {s-cw-ch, ch};
      c2 = {cw+cw+ch-s, ch};
    }else if(cw<s && s< cw+ch){
      c1 = {cw, s-cw};
      c2 = {cw, cw+ch-s};
    }else{
      c1 = {cw, s-cw-cw-ch};
      c2 = {cw, cw+ch+cw+ch-s};
    }

    if(c1.first*c1.second > c2.first*c2.second)swap(c1,c2);

    cakes.push_back(c1);
    cakes.push_back(c2);

    // cakes.insert(cakes.begin()+p, c1);
    // cakes.insert(cakes.begin()+p+1, c2);
  }

  vector<int>s;
  rep(i, cakes.size())s.push_back(cakes[i].first*cakes[i].second);
  sort(s.begin(), s.end());

  rep(i, s.size()){
    cout<<s[i];
    if(i<s.size()-1)cout<<' ';
  }

  cout<<endl;
}

int main(){
  while(cin>>n>>w>>h){
    if(w==0)break;

    solve();
  }

  return 0;
}
