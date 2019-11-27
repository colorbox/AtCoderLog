#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;
  cin>>n;
  if(n%2==0){
    n--;
  }else{
    n++;
  }

  cout<<n<<endl;
  return 0;
}
