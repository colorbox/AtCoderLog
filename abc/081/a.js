function main(input) {
  const input_array = input.split('');
  const result = input_array.filter(word => word == '1');
  console.log(result.length);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

