function compareNumbers(a, b) {
  return a - b;
}

function main(input) {
  const input_array = input.split("\n");
  const cards = input_array[1].split(' ').map(x => parseInt(x, 10)).sort(compareNumbers).reverse();
  
  var alice = 0;
  var bob = 0;
  
  for(i=0; i<cards.length; i++){
    if(i%2==0){
      alice+=cards[i];
    }else{
      bob+=cards[i];
    }
  }
  
  console.log(alice-bob);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

