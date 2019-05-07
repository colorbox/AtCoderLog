function sadness(b, A){
  var result = 0;
  for(var i=0;i<A.length;i++){
    result += Math.abs(A[i]-(b+i+1))
  }
  return result;
}

function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines[0]);
  const As = lines[1].split(' ').map(x => parseInt(x));

  const median_index = Math.floor(N/2);
  var sorted_A_diffs = [];
  for(var i=0;i<As.length;i++){
    sorted_A_diffs.push(As[i]-(i+1));
  }
  sorted_A_diffs.sort(function(a,b){return a-b;});
  const b = sorted_A_diffs[median_index];

//  console.log(N);
//  console.log(As);
//  console.log(sorted_A_diffs);
//  console.log([median_index,b, sorted_A_diffs[median_index+1]]);
//  console.log([sadness(b, As), sadness(sorted_A_diffs[median_index+1], As)]);
  var result = sadness(b, As);

  // This is why `Math.min([sadness(b, As), sadness(sorted_A_diffs[median_index+1], As)])` fails
  // Maybe when N=2 fail below;
//  if((median_index+1)!=N){
//    result = Math.min(result, sadness(sorted_A_diffs[median_index+1], As));
//  }


  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
