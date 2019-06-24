'use strict'

function topological_sort(nodes_count, in_count, outs){
  let start_nodes = Array.from(Array(nodes_count+1).keys()).filter(x => in_count[x]==0)
  start_nodes.shift()

  let result = [];
  let from = start_nodes.shift();
  while(from != undefined){
    result.push(from);
    for(let out_node of outs[from]){
      in_count[out_node]--;
      if(in_count[out_node]==0){ start_nodes.push(out_node); }
    }
    from = start_nodes.shift();
  }

  return result;
}

function main(input){
  const lines = input.split('\n');
  const NM = lines.shift().split(' ').map(x => parseInt(x));
  const N = NM[0];
  const M = NM[1];
  const XY = []
  for(var i=0;i<M;i++){
    let xy = lines.shift().split(' ').map(x => parseInt(x));
    XY.push(xy);
  }

  let ins = [];
  let outs = [];
  let in_count = []
  for(var i=0;i<N+1;i++){
    ins.push([]);
    outs.push([]);
  }

  for(var i=0;i<M;i++){
    let x = XY[i][0];
    let y = XY[i][1];
    ins[y].push(x);
    outs[x].push(y)
  }
  in_count = ins.map(x => x.length)

//  console.log(ins);
//  console.log(outs);
//  console.log(in_count);

  let topological_nodes = topological_sort(N, in_count, outs);
//  console.log(topological_nodes);

//  console.log('---');
  let dp=Array(N+1).fill(0);
//  console.log(dp);
  for(let current of topological_nodes){
//    console.log( [current, ins[current], ins[current].map(x => dp[x])] );
    dp[current] = Math.max(...ins[current].map(x => dp[x]+1).concat(0) )
  }
//  console.log(dp);
//  console.log('---');


  let result = Math.max(...dp);
  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
