function main(input) {
  const formatted_input = input.split('\n')[0];
  const b = formatted_input;
  var result = '';
  if(b=='A'){result='T'}
  if(b=='T'){result='A'}
  if(b=='G'){result='C'}
  if(b=='C'){result='G'}
  console.log(result);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

