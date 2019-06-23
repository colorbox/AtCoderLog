'use strict'

function main(input) {
  const lines = input.split('\n');

  const c = [];
  for(let i=0;i<3;i++){
    c.push(lines[i].split(' ').map(x => parseInt(x)))
  }

  let result = 'Yes';

  if(c[1][1]+c[2][2] != c[1][2]+c[2][1]){result='No';}
  if(c[0][0]+c[1][1] != c[0][1]+c[1][0]){result='No';}
  if(c[0][0]+c[2][2] != c[0][2]+c[2][0]){result='No';}

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
