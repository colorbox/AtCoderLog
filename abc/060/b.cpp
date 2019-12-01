#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int a,b,c;cin>>a>>b>>c;

  if(a%b==c){
    cout<<"YES";return 0;
  }
  int result = a;
  rep(i,b){
    result += a;
    if(result%b==c){
      cout<<"YES";return 0;
    }
  }

 cout<<"NO";
 
  return 0;
}
