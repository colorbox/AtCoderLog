'use strict'

function main(input){
  const lines = input.split('\n');
  const S = lines[0];
  const T = lines[1];

  let tIndices = [];
  for(let i=0;i<S.length-T.length+1;i++){
    let same_count=0;
    for(let j=0;j<T.length;j++){
      let partS = S.slice(i,i+T.length).split('');
      let partT = T.split('');
      if( partS[j]=='?' || partS[j]==partT[j]){
        same_count++;
      }
    }
    if(same_count==T.length){
      tIndices.push(i);
    }
  }

//  console.log(tIndices);

  if(tIndices.length==0){
    console.log('UNRESTORABLE');
    return;
  }

  let results =[];

  for(let tIndex of tIndices){
    let current = []
    for(let i =0;i<S.length;i++){
      if(i>=tIndex && i < tIndex+T.length){
        current.push(T[i-tIndex]);
      }else{
        if(S[i]=='?'){
          current.push('a');
        }else{
          current.push(S[i]);
        }
      }
    }
    results.push(current.join(''));
  }

  console.log(results.sort()[0]);
}

main( require('fs').readFileSync('/dev/stdin','utf8') )
