function main(input){
  const lines = input.split('\n');
  const N  = parseInt(lines[0]);
  const A  = lines[1].split(' ').map(x => parseInt(x));

  var result = 0;
  for(var i=0;i<A.length;i++){
    result += A[i]-1;
  }
  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

