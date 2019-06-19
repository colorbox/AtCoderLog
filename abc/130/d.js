function main(input){
  const lines = input.split('\n')
  const N = lines[0].split(' ').map(x => parseInt(x))[0];
  const K = lines[0].split(' ').map(x => parseInt(x))[1];
  const A = lines[1].split(' ').map(x => parseInt(x));

  const cum_a = [A[0]];
  for(var i=1;i<N;i++){
    cum_a[i] = A[i] + cum_a[i-1];
  }

  var result = 0;

  var start_index = 0;
  for(var i=0;i<N;i++){
    var current_cum_a = cum_a[i];
    if(current_cum_a >= K){
      result++;
    }else{
      start_index++;
    }
  }

  for(var i=0;i<N-1;i++){
    var current_cum_a = cum_a[i];

    var current_start_index = start_index;
    while(current_start_index<N){
      var target = cum_a[start_index];
      if(target - current_cum_a >= K){
        result+=(N-current_start_index);
        break;
      }else{
        start_index++;
      }
      current_start_index++;
    }
  }

//  console.log(cum_a);
  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
