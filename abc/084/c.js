'use strict'

function main(input){

  const lines = input.split('\n');
  const N = parseInt(lines.shift());
  const C = [];
  const S = [];
  const F = [];
  for(let i=0;i<N-1;i++){
    let csf =lines[i].split(' ').map( x => parseInt(x));
    C.push(csf[0]);
    S.push(csf[1]);
    F.push(csf[2]);
  }

  let result = [];

  if(N==2){
    console.log(S[0]+C[0]);
    console.log(0);
    return;
  }
  if(N==1){
    console.log(0);
    return;
  }

  for(let i=0;i<N-1;i++){
    let current_start_time = S[i];
    for(let j=i;j<N-2;j++){
      let additional_wait_time = Math.max( 0, Math.ceil( (current_start_time+C[j]-S[j+1])/F[j+1] ) ) * F[j+1];
      current_start_time = S[j+1]+additional_wait_time;

//      console.log([current_start_time, additional_wait_time] );

    }
    current_start_time += C[N-2];
    result.push(current_start_time);
  }
  result.push(0);

  for(let i=0;i<N;i++){
    console.log(result[i]);
  }

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
