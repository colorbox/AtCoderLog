#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll INF = 1e11;
ll n, m, l, q;
ll graph[311][311];
ll graph2[311][311];
ll st[300*300+1][2];
ll abc[300*300+1][3];


void input(){
  cin>>n>>m>>l;
  for(int i=0;i<m;i++){cin>>abc[i][0]>>abc[i][1]>>abc[i][2];}
  cin>>q;
  for(int i=0;i<q;i++){cin>>st[i][0]>>st[i][1];}
}

int main(){
  input();

  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      graph[i][j]=INF;
      graph2[i][j]=INF;
    }
    graph[i][i]=0;
    graph2[i][i]=0;
  }

  for(int i=0; i<m; i++){
    graph[abc[i][0]][abc[i][1]] = abc[i][2];
    graph[abc[i][1]][abc[i][0]] = abc[i][2];
  }

  for(int k=0; k<=n; k++){
    for(int i=0; i<=n; i++){
      for(int j=0; j<=n; j++){
        if (graph[i][j] > graph[i][k] + graph[k][j]){graph[i][j] = graph[i][k] + graph[k][j];}
      }
    }
  }

  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      if(graph[i][j] <= l){graph2[i][j] = 1;}
    }
  }

  for(int k=0; k<=n; k++){
    for(int i=0; i<=n; i++){
      for(int j=0; j<=n; j++){
        if (graph2[i][j] > graph2[i][k] + graph2[k][j]){graph2[i][j] = graph2[i][k] + graph2[k][j];}
      }
    }
  }

  for(int i=0; i<q; i++){
    ll result = graph2[st[i][0]][st[i][1]]==(INF) ? -1 : graph2[st[i][0]][st[i][1]]-1;
    cout <<result << endl;
  }

 return 0;
}
