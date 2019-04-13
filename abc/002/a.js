function main(input) {
  const info = input.split(' ').map(x => parseInt(x, 10));
  
  if(info[0] > info[1]){
    console.log(info[0]);
  }else{
    console.log(info[1]);
  }
  
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

