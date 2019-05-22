function main(input) {
  const formatted_input = input.split('\n');

  const N = formatted_input[0];
  const S = formatted_input[1];
  const K = formatted_input[2];

  var target = S.split('')[K-1]

  var result = [];
  for(var i=0; i<N ;i++ ){
    var current = S[i];
    if(current==target){
      result.push(current);
    }else{
      result.push('*');
    }
  }
  console.log(result.join(''));
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
