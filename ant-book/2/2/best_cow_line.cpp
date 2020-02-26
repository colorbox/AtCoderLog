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

int main(){
  string s="ACDBCB";
  vector<char> t;

  int l=0,r=s.size()-1;
  rep(i, s.size()){
    if(l==r)t.push_back(s[l]);
    if(s[l]>s[r]){
      t.push_back(s[r]);
      r--;
    }else if(s[l]<s[r]){
      t.push_back(s[l]);
      l++;
    }else{

      rep(i, (r-l)/2){
        if(s[l+1+i]>s[r-1-i]){
          t.push_back(s[r]);
          r--;
          break;
        }else if(s[l+1+i]<s[r-1-i]){
          t.push_back(s[l]);
          l++;
          break;
        }
      }
    }
  }

  rep(i, t.size())cout<<t[i];cout<<endl;

  return 0;
}
