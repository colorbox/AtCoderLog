#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long a[3*n];
  long long f[n+1], l[n+1];
  long long sum_f=0, sum_l=0;
  for(int i=0;i<3*n;i++){
    cin>>a[i];
  }

  priority_queue<long long, vector<long long>,greater<long long>> qf;
  for(int i=0;i<n;i++){
    qf.push(a[i]);
    sum_f += a[i];
  }
  f[0]=sum_f;

  for(int i=0;i<n;i++){
    qf.push(a[n+i]);
    sum_f += a[n+i];
    sum_f -= qf.top();
    qf.pop();
    f[i+1]=sum_f;
  }

  priority_queue<long long, vector<long long>, less<long long>> ql;
  for(int i=0;i<n;i++){
    ql.push(a[2*n+i]);
    sum_l+=a[2*n+i];
  }
  l[n]=sum_l;

  for(int i=0;i<n;i++){
    ql.push(a[2*n-1-i]);
    sum_l += a[2*n-1-i];
    sum_l -= ql.top();
    ql.pop();
    l[n-1-i]=sum_l;
  }

  long long result=f[0]-l[0];
  for(int i=0;i<n+1;i++){
    if(f[i]-l[i]>result){
      result = f[i]-l[i];
    }
  }

  cout<<result<<endl;

  return 0;
}