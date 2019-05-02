'use strict'

function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines[0].split(' ')[0]);
  const K = parseInt(lines[0].split(' ')[1]);
  var hs = [];
  for(var i=0;i<N;i++){
    hs.push(parseInt(lines[i+1]));
  }
  const sorted_hs = hs.sort(function(a,b){return a-b;})
  var part_hs = []
  for(var i=0;i<K;i++){part_hs.push(sorted_hs[i])}
  var result = part_hs[part_hs.length-1] - part_hs[0];

  for(var i=1;i<N-K+1;i++){
    part_hs.shift();
    part_hs.push(sorted_hs[i+K-1]);

    var current_diff = part_hs[part_hs.length-1] - part_hs[0];
    result = Math.min(result, current_diff)
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
