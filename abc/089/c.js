'use strict'

function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines.shift());
  const S = [];
  for(let i=0;i<N;i++){
    S.push(lines[i].split(''))
  }
  const march=Array(5).fill(0);

  for(let i=0;i<N;i++){
    if( lines[i][0]=='M' ){ march[0]++; }
    if( lines[i][0]=='A' ){ march[1]++; }
    if( lines[i][0]=='R' ){ march[2]++; }
    if( lines[i][0]=='C' ){ march[3]++; }
    if( lines[i][0]=='H' ){ march[4]++; }
  }

//march.fill(3000)

//  console.log(march)

  let result = 0;

  for(let i = 0;i<3;i++){
    for(let j = i+1;j<4;j++){
      for(let k = j+1;k<5;k++){
//        console.log([i,j,k])
//        console.log(march[i]*march[j]*march[k]);
//console.log(result);
//console.log('---');
        result += march[i]*march[j]*march[k];
      }
    }
  }

  console.log(result);

}

main( require('fs').readFileSync('/dev/stdin','utf8') );
