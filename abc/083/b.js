function main(input) {
  const input_array = input.split(' ');

  const N = input_array[0];
  const A = input_array[1];
  const B = input_array[2];
  
  var answer = 0;
  const reducer = (accumulator, currentValue) => accumulator + currentValue;

  for (i=1; i<=N; i++){
    sum = i.toString().split("").map( x => parseInt(x, 10)).reduce(reducer)
    if(A <= sum && sum <= B){
      answer+=i;
    }
  }
  
  console.log(answer);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'))

