#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  double a,b,x;cin>>a>>b>>x;

  double theta;
  if(x>a*a*b*0.5){
    theta=atan(2*(a*a*b-x)/(a*a*a));
  }else{
    theta=atan(a*b*b/(2*x));
  }

//  cout<<theta<<endl;
  cout<<fixed<<setprecision(10)<<theta/(M_PI/180.0);

  return 0;
}
