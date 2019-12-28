#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

bool compare_by_second2(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second < b.second;
}

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }

  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }

  bool findSet(int x, int y) {
    return root(x) == root(y);
  }

  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  int size(int x) {
    return -data[root(x)];
  }
};

int print_queue(queue<int> q){
  while (!q.empty()){
    cout << q.front()+1 << " ";
    q.pop();
  }
  return 0;
}

vector< pair<pair<int, int>, int> > roads;

int main(){
  int n,m;cin>>n>>m;
  rep(i,m){
    int a,b,y;cin>>a>>b>>y;a--;b--;
    auto p = make_pair(a,b);
    roads.push_back(make_pair(p, y));
  }
  int q;cin>>q;
  vector<pair<int, int>> people;
  rep(i,q){
    int v,w;cin>>v>>w;v--;
    people.emplace_back(v, w);
  }
  vector<pair<int, int>> p(people);

  sort(people.rbegin(), people.rend(), compare_by_second);
  sort(roads.rbegin(), roads.rend(), compare_by_second2);

  struct UnionFind uf(n);
  map<pair<int,int>,int>logger;

  int road_i=0;
  int yc=people[0].second;
  rep(i,q){
    int oldest = people[i].second;
    int current_city = people[i].first;
    while(oldest < roads[road_i].second){
      uf.unionSet(roads[road_i].first.first, roads[road_i].first.second);
      road_i++;
    }
    logger[people[i]]=uf.size(current_city);
  }

  rep(i,p.size()){
    cout<<logger[p[i]]<<endl;
  }

  return 0;
}
