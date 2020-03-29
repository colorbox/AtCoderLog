#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000.0

using namespace std;

struct UnionFind {
  vector<int> data;

  UnionFind(int n){
    data.resize(n+1);
    fill(data.begin(), data.end(), -1);
  }

  int root(int x){
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  void unite(int x, int y){
    int rx=root(x);
    int ry=root(y);

    if(rx!=ry){
      if(data[ry] < data[rx])swap(rx, ry);

      data[rx]+=data[ry];
      data[ry]=rx;
    }
  }

  bool same(int x, int y){
    return root(x)==root(y);
  }

  int size(int x){
    return -data[root(x)];
  }
};

int n;
#define MAXN 100

double x[MAXN], y[MAXN], z[MAXN], r[MAXN];
vector<pair<double, pi>> edges;

double square(double n){ return n*n; }

double solve(){
  edges.clear();

  rep(i, n)rep(j, n){
    if(i==j)continue;
 
    double dist = square(x[i]-x[j])+square(y[i]-y[j])+square(z[i]-z[j]);
    dist = pow(dist, 0.5);
    double cost=0.0;
    
    // 非接触
    if( dist > r[i]+r[j] ){
      cost = dist - (r[i]+r[j]);
    // }else if(max<double>(r[i], r[j]) > dist+min<double>(r[i], r[j]) ){
      // 内包
      // cost = max<double>(r[i], r[j]) - (dist+min<double>(r[i], r[j]) );
    }
    edges.push_back({cost, {i, j}});
  }

  sort(edges.begin(), edges.end());

  double result=0.0;
  UnionFind uf(n);
  for(auto p: edges){
    pi pp = p.second;
    if(!uf.same(pp.first, pp.second)){
      result += p.first;
      uf.unite(pp.first, pp.second);
    }
  }
  return result;
}

int main(){

  while(cin>>n){
    if(n==0)break;

    rep(i, n)cin>>x[i]>>y[i]>>z[i]>>r[i];

    cout<<fixed<<setprecision(3)<<solve()<<endl;
  }

  return 0;
}
