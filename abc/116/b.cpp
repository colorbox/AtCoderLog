#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int f(int n){
  if(n%2==0){
    return n/2;
  }else{
    return 3*n+1;
  }
}

int main(){
  int last;cin>>last;

  set<int> ss;
  ss.insert(last);

  int counter=2;
  while(true){
    int c=f(last);
//cout<<c<<' '<<last<<endl;
    if(ss.count(c)==1){
      cout<<counter;
      break;
    }
    counter++;
    ss.insert(c);
    last=c;
  }

  return 0;
}
