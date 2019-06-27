'use strict'

function main(input){
  const lines = input.split('\n');
  const ABCDEF = lines.shift().split(' ').map(x => parseInt(x));
  const A = ABCDEF[0];
  const B = ABCDEF[1];

  const C = ABCDEF[2];
  const D = ABCDEF[3];

  const E = ABCDEF[4];
  const F = ABCDEF[5];

  let water = [];
  let sugers = [];
  for(let i=0;i<=F;i++){
    for(let j=0;j<=F;j++){
      let current_water = 100*(A*i+B*j);
      if(current_water<=F){ water.push(current_water); }

      let current_suger = C*i + D*j;
      if(current_suger<=F){ sugers.push(current_suger); }
    }
  }

  let results = [];
  let limit_density = 100*E/(100+E);

  for(let i=0;i<water.length;i++){
    for(let j=0;j<sugers.length;j++){
      let total = water[i] + sugers[j];
      let melt_suger = 100*sugers[j]/water[i];
      if( (total <= F) && (melt_suger <= E) ){
        results.push([water[i], sugers[j]]);
      }
    }
  }

  let tmp_melt_suger = 0;
  let idx = 0;
  for(let i=0;i<results.length;i++){
    let current_suger = (100*results[i][1])/(results[i][0]+results[i][1]);
    if(current_suger > tmp_melt_suger){
      tmp_melt_suger = current_suger;
      idx = i;
    }
  }
  console.log((results[idx][0] + results[idx][1])+' '+results[idx][1]);
}

main( require('fs').readFileSync( '/dev/stdin', 'utf8') );
