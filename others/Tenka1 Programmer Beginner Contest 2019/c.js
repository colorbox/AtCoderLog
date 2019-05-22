function main(input) {
  const formatted_input = input.split('\n');

  const N = parseInt(formatted_input[0], 10);
  const S = formatted_input[1];

  var count = 0;
  var result = N;


  var left_count = 0;
  var right_count=0;
  for(var i = 0 ; i < N ; i++){
    var current = S[i];
    if(current=='.'){right_count++;}
  }

  result = Math.min(result, right_count+left_count);

  for(var i = 0 ; i < N ; i++){
    var current = S[i];
    if(current=='#'){
      left_count++;
    }
    if(current=='.'){right_count--;}
    result = Math.min(result, right_count+left_count);

    //console.log('---');
    //console.log(`${result},${left_count},${right_count},${i}`);
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
