#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll h,w,k;
  cin>>h>>w>>k;
  
  vector<vector<ll>> b;
  rep(i,h){
    vector<ll> t(w);
    rep(i,w){
      t[i]=0;
    }
    b.push_back(t);
  }
  ll s=1;
  rep(i,h){
    string t;
    cin>>t;
    rep(j,w){
      if(t[j]=='#'){
        b[i][j]=s++;
      }
    }
  }

  ll c=0;
  rep(i,h){
    rep(j,w){
      if(b[i][j]!=0 && b[i][j]!=c){
        c=b[i][j];
      }
      b[i][j]=c;
    }
    rep(j,w){
      ll jj=w-1-j;
      if(b[i][jj]!=0 && b[i][jj]!=c){
        c=b[i][jj];
      }
      b[i][jj]=c;
    }
    c=0;
  }
  
  c=0;
  rep(j,w){
    rep(i,h){
      if(b[i][j]!=0 && b[i][j]!=c){
        c=b[i][j];
      }
      b[i][j]=c;
    }
    rep(i,h){
      ll ii=h-1-i;
      if(b[ii][j]!=0 && b[ii][j]!=c){
        c=b[ii][j];
      }
      b[ii][j]=c;
      
    }
    c=0;
  }

  
  rep(i,h){
    rep(j,w){
      cout<<b[i][j]<<' ';
    }
    cout<<endl;
  }

  return 0;
}
