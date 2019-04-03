function main(input) {
  const input_array = input.split('\n');
  var mochis = [];
  const mochi_count = input_array[0];

  for(i=0; i<mochi_count;i++){
    mochis[i] = input_array[i+1]
  }

  console.log(Array.from(new Set(mochis)).length);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

