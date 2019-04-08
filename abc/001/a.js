function main(input) {
  const input_array = input.split('\n');
  
  console.log(parseInt(input_array[0], 10) - parseInt(input_array[1], 10));
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

