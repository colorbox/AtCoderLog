function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines[0].split(' ')[0]);
  const K = parseInt(lines[0].split(' ')[1]);
  const Xs = lines[1].split(' ').map(x => parseInt(x))

  var result = 1e9;
  for(var i=0;i<N-K+1;i++){
    var min = Xs[i];
    var max = Xs[i+K-1];

    var right = Math.abs(max-min)+Math.abs(max);
    var left = Math.abs(max-min)+Math.abs(min);

    result = Math.min(...[result,left, right]);
    //console.log([i,result,min,max]);
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
