#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s,t;cin>>s>>t;

  sort(s.begin(),s.end());
  sort(t.rbegin(),t.rend());

//cout<<s<<endl;
//cout<<t<<endl;

  if(s<t){
    cout<<"Yes";
  }else{
    cout<<"No";
  }


  return 0;
}
