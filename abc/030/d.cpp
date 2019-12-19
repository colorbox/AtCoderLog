#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,a;cin>>n>>a;
  string k;cin>>k;
  vector<int> b(n);
  int logger[100010];
  rep(i, 100010)logger[i]=-1;
  
  rep(i,n){
    int t;cin>>t;t--;
    b.insert(b.begin()+i, t);
  }

  //閉路と余分な長さを測定
  int start,closing,tail;
  
  int current=a-1;
  logger[current]=0;
  rep(i,n){
    if(logger[b[current]]>=0){
      start=b[current];
      closing=i-logger[b[current]]+1;
      tail=logger[b[current]];
      break;
    }else{
      logger[b[current]]=i+1;
      current = b[current];
    }
  }

  if(k.size()<=6 && stoi(k)<=tail){
    rep(i, n)if(logger[i]==stoi(k)-1){cout<<b[i]+1<<endl;return 0;}
  }

  int result_count=0;
  result_count -= tail;
  result_count = (result_count+closing*n)%closing;
  int digit = 1;
  rep(i, k.size()){
    int c = k.size()-1-i;
    int target = (int)(k[c]-'0');

    result_count += (target*digit)%closing;
    digit  = digit*10%closing;
  }

  int result=start;
  rep(i,result_count){
    result = b[result];
  }
  cout<<result+1<<endl;

  return 0;

cout<<endl;
//cout<<n<<a<<endl;
//cout<<k<<endl;
cout<<tail<<endl;
cout<<start<<endl;
cout<<closing<<endl;

rep(i,n)cout<<b[i];cout<<endl;
rep(i,n)cout<<logger[i];cout<<endl;

  return 0;
}
