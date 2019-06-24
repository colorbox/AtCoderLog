'use strict'

function main(input){
  const lines = input.split('\n');

  const ABCD = lines.shift().split('').map(x => parseInt(x));
  const A = ABCD[0];
  const B = ABCD[1];
  const C = ABCD[2];
  const D = ABCD[3];

  for(var i=0;i<8;i++){
    let operators = (8+i).toString(2).split('').map(function(x){if(x=='1'){return '+'}else{return '-'}}).slice(1,4)
    let seven = A;
    for(let j=0;j<3;j++){
      if(operators[j]=='+'){
        seven += ABCD[j+1]
      }else{
        seven += -1 *  ABCD[j+1]
      }
    }
    if(seven==7){
      let result = `${A}${operators[0]}${B}${operators[1]}${C}${operators[2]}${D}=7`;
      console.log(result);

      return
    }
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
