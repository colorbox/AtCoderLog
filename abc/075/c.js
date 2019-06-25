'use strict'

function dfs(node, graph, visited){
  visited[node]=true;
  for(let i=0;i<graph[node].length;i++){
    if(graph[node][i]==false || visited[i]==true){continue;}
    dfs(i, graph, visited);
  }
}

function main(input){
  const lines = input.split('\n');
  const NM  =lines.shift().split(' ').map(x => parseInt(x));
  const N = NM[0];
  const M = NM[1];
  const sides = [];
  const graph = [];
  const visited = Array(N).fill(false);
  for(let i=0;i<N;i++){
    graph.push( Array(N).fill(false) );
  }

  for(let i=0;i<M;i++){
    let current = lines.shift().split(' ').map( x=>parseInt(x) );
    graph[current[1]-1][current[0]-1]=graph[current[0]-1][current[1]-1]=true
    sides.push(current);
  }

  let result=0;
  for(let i=0;i<M;i++){
    let current = sides[i];
    graph[current[1]-1][current[0]-1]=graph[current[0]-1][current[1]-1]=false

    for(let j=0;j<N;j++){visited[j]=false;}

    dfs(0, graph, visited);

    for(let j=0;j<N;j++){
      if(!visited[j]){
//console.log(current);
//console.log(visited);
//console.log('---');
        result++;
        break;
      }
    }
    graph[current[1]-1][current[0]-1]=graph[current[0]-1][current[1]-1]=true
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
