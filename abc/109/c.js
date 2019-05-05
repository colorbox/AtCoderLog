function gcd(a,b){
  if(b==0){return a;}
  return gcd(b, a%b);
}

function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines[0].split(' ')[0]);
  const X = parseInt(lines[0].split(' ')[1]);
  const Xs = lines[1].split(' ').map(x => parseInt(x))

  Xs.push(X)
  Xs.sort(function(a,b){return a-b;})

  var diff_xs = [];
  for(var i=0;i<Xs.length-1;i++){
    diff_xs.push(Xs[i+1] - Xs[i]);
  }

  var result = diff_xs[0];
  for(var i=1;i<diff_xs.length;i++){
    result = gcd(result, diff_xs[i]);
  }

  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
