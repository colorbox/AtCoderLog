//from https://eagletmt.github.io/contests/blog/poj-2431/
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n=0;
  cin>>n;


  vector<pair<int,int>> fuels;
  for(int i=0;i<n;i++){
    int f,s;
    cin>>f>>s;
    auto cp = make_pair(f, s);
    fuels.push_back(cp);
  }

  int l, p;
  cin>>l>>p;

  // sort(fuels.begin(), fuels.end(),greater<pair<int, int>>());

  int ans = 0;
  int rest = l-p;
  priority_queue<int> q;

  cout<<endl;
  cout<<endl;

  while(rest > 0){
    cout<<rest<<endl;
    cout<<ans<<endl;
    
    vector<pair<int, int>>::const_iterator it = fuels.begin();

    cout<<rest<<' ';
    while(it != fuels.end()){
      if(it->first >= rest){cout<<"####";}
      it++;
    }
    cout<<endl;

    it = fuels.begin();

    while(it != fuels.end()){
      cout<<it->first<<' '<<it->second<<" |";
      if(it->first >= rest){
        q.push(it->second);
        cout<<"####";
      }
      it++;
    }

    remove_if(fuels.begin(), fuels.end(), [rest](pair<int, int> x){ return x.first >= rest; });

    if(q.empty()){
      ans = -1;
      break;
    }

    rest -= q.top();
    q.pop();
    ans++;
  }
  cout<<ans<<endl;
  
  return 0;
}
