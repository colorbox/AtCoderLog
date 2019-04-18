function main(input) {
  const formatted_input = input.split('\n')[0].split(' ').map( x => parseInt(x, 10) );

  const A = formatted_input.sort()[2];
  const B = formatted_input.sort()[1];
  const C = formatted_input.sort()[0];

  console.log(10*A + B + C);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

