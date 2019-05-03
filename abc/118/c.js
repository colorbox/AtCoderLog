function gcd(a,b){
  if(b==0){return a;}
  return gcd(b,a%b);
}

function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines[0]);
  const As = lines[1].split(' ').map(x => parseInt(x));

  var result = As[0];
  for(var i=1;i<N;i++){
    result = gcd(result, As[i])
  }
  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
