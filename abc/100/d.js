'use strict'

function cake_score(array){
  return Math.abs(array[0]) + Math.abs(array[1]) + Math.abs(array[2])
}

function main(input){
  const lines = input.split('\n');
  const NM = lines.shift().split(' ').map(x => parseInt(x));
  const N = NM[0];
  const M = NM[1];

  const cakes = [];
  for(var i=0;i<N;i++){
    cakes.push( lines.shift().split(' ').map(x => parseInt(x)) )
  }

  let patterns = [
    [1,1,1],
    [1,-1,1],
    [1,1,-1],
    [1,-1,-1],
    [-1,1,1],
    [-1,-1,1],
    [-1,1,-1],
    [-1,-1,-1]
  ];

  let cake_patterns = [];
  for(let p of patterns){
    let current_scores = cakes.map(cake =>
      cake[0]*p[0] + cake[1]*p[1] + cake[2]*p[2]
    ).sort(function(a,b){return b-a;})

    cake_patterns.push(current_scores);
  }

//  console.log(cake_patterns);

  let m_cakes_score_pattern = cake_patterns.map( scores => scores.slice(0,M).reduce((a,b) => a + b, 0) )

//  console.log(m_cakes_score_pattern);

  let result = Math.max(...m_cakes_score_pattern);
  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
