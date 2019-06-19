function main(input){
  const lines = input.split('\n')
  const W = lines[0].split(' ').map(x => parseInt(x))[0];
  const H = lines[0].split(' ').map(x => parseInt(x))[1];
  const x = lines[0].split(' ').map(x => parseInt(x))[2];
  const y = lines[0].split(' ').map(x => parseInt(x))[3];

  var result = W*H/2;
  var flag = 0;

  if(x==W/2 && y==H/2){
    flag=1;
  }

  console.log('%s %s',result, flag);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
