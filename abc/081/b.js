function last_zero_count(str) {
  n=0;
  for (hoge of str.split('').reverse()){if(hoge=='0'){n++;}if(hoge=='1'){break;}}
  return n;
}
 
 
function main(input) {
  const args = input.split("\n");
  const line_count = args[0];
  const numbers = args[1].split(' ')
 
  const zero_count_array = numbers.map(x => last_zero_count(parseInt(x).toString(2)));
  
  console.log(Math.min.apply(null, zero_count_array));
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

