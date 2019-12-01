#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string n;cin>>n;

  int sn = 0;
  rep(i, n.size()){
    sn+=(int)(n.at(i)-'0');
  }

//cout<<n<<endl;
//cout<<sn<<endl;

  if(stoi(n)%sn==0){
    cout<<"Yes";
  }else{
    cout<<"No";
  }

  return 0;
}
