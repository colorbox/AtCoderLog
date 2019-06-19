function main(input){
  const lines = input.split('\n')
  const N = lines[0].split(' ').map(x => parseInt(x))[0];
  const X = lines[0].split(' ').map(x => parseInt(x))[1];
  const L = lines[1].split(' ').map(x => parseInt(x));

  var result = 1;
  var len = 0;
  for(var i=0;i<N;i++){
    len+=L[i];
    if(len > X){
      break;
    }
    result++;
  }

  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
