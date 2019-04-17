function main(input) {
  const formatted_input = input.split(' ').map( x => parseInt(x, 10) );
  const A = formatted_input[0];
  const B = formatted_input[1];
  const C = formatted_input[2];

  if(A*C <= B){
    console.log(C);
  }else{
    console.log(parseInt(B/A));
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

