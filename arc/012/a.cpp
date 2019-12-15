#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string day;cin>>day;

  string checker = "SuSaFrThWeTuMo";
  cout<<max(0, (int)checker.find(day.substr(0, 2))/2-1)<<endl;

  return 0;
}
