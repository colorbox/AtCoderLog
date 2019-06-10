function main(input){
  const lines = input.split('\n')
  const N = parseInt(lines.shift());
  const W = lines.shift().split(' ').map(x => parseInt(x));
  var cum_array = [W[0]];
  for(var i=1;i<N;i++){
    cum_array.push(cum_array[i-1]+W[i])
  }
  var result = Infinity;

  for(var i=1;i<N;i++){
    var current_result = Math.abs(cum_array[N-1] - cum_array[i] - cum_array[i])
    if(current_result < result){result = current_result;}
  }

//  console.log(cum_array);
  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
