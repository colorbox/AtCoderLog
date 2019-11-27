#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;
  string name;
  int sum=0;
  int c=0;
  cin>>n;
  rep(i,n){
    string cname;
    int p;
    cin>>cname>>p;
    sum+=p;
    if(p>c){
      c=p;
      name=cname;
    }
  }

  if((double)c/sum > 0.5){
    cout<<name<<endl;
  }else{
    cout<<"atcoder"<<endl;
  }

  return 0;
}
