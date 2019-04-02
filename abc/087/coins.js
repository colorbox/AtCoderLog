// 500, 100, 50
function main(input) {
  const input_array = input.split("\n");

  const a = parseInt(input_array[0], 10);
  const b = parseInt(input_array[1], 10);
  const c = parseInt(input_array[2], 10);
  const desired_sum = parseInt(input_array[3], 10);a
  //  const desired_sum = parseInt(input_array.slice(-1), 10);// wrong

  
  var answer = 0;
  for(i=0; i<=a; ++i){
    for(j=0; j<=b; ++j){
      for(k=0; k<=c; ++k){
        if (500 * i + 100 * j + 50 * k == desired_sum){
          answer+=1;
        }
      }
    }
  }
  
  console.log(answer);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));



