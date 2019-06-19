function main(input){
  const NK = input.split(' ').map(x => parseInt(x))

  if(NK[1]==1){
    console.log(0);
  }else{
    console.log(NK[0]-NK[1]);
  }

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
