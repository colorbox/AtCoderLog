function main(input) {
  const formatted_input = input.split('\n').map(x => parseInt(x));

  if(formatted_input[4] - formatted_input[0] > formatted_input[5]){
    console.log(':(')
  }else{
    console.log('Yay!')
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
