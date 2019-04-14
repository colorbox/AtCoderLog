function main(input) {
  const inputs = input.split('\n')[0].split('').map( x => parseInt(x, 10))
  const length = inputs.length
 
  surface = 0;
  reverse = 0;
  for(i=0; i<length; i++){
    current_char = inputs[i]
    if(i%2==0){
      if(current_char==0){
        surface++;
      }else{
        reverse++;
      }
    }else{
      if(current_char==0){
        reverse++;
      }else{
        surface++;
      }
    }
  }
 
  console.log(Math.min(surface, reverse));
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

