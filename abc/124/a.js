function main(input) {
  const inputs = input.split('\n')[0].split(' ').map( x => parseInt(x, 10))
  answer = 0
  if (inputs[0] > inputs[1]){
    answer += inputs[0];
    inputs[0] = inputs[0]-1;
  }else{
    answer += inputs[1];
    inputs[1] = inputs[1]-1;
  }
 
  if (inputs[0] > inputs[1]){
    answer += inputs[0];
    inputs[0] = inputs[0]-1;
  }else{
    answer += inputs[1];
    inputs[1] = inputs[1]-1;
  }
 
  console.log(answer);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

