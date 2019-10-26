#include<bits/stdc++.h>

using namespace std;

main(){
  int n;
  cin>>n;

  typedef pair<int, int> P;
  vector<P> a;
  for(int i=1;i<=n;i++){
    int num;
    cin >> num;
    a.push_back( P(num, i) );
  }

  for(int i=0;i<n;i++){
//    cout<<a[i].first<<' '<<a[i].second<<'|';
  }
//  cout<<endl;

  sort(a.begin(), a.end());

  for(int i=0;i<n;i++){
//    cout<<a[i].first<<' '<<a[i].second<<'|';
  }
//  cout<<endl;

  for(int i=0;i<n;i++){
    cout<<a[i].second<<' ';
  }
  cout<<endl;
}
