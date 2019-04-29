function main(input) {
  const formatted_input = input.split('\n');
  const W =  parseInt(formatted_input[0].split(' ')[0]);
  const H =  parseInt(formatted_input[0].split(' ')[1]);
  const w =  parseInt(formatted_input[1].split(' ')[0]);
  const h =  parseInt(formatted_input[1].split(' ')[1]);

  console.log( W*H - (h*W + (H-h)*w) );

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

