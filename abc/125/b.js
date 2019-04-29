function main(input) {
  const formatted_input = input.split('\n');

  const N = parseInt(formatted_input[0], 10);
  const Vs = formatted_input[1].split(' ').map(x => parseInt(x));
  const Cs = formatted_input[2].split(' ').map(x => parseInt(x));

  values = [];
  for(var i=0 ; i<N ; i++){
    values.push(Vs[i] - Cs[i]);
  }

  values.sort().reverse();

  var acc_values = [values[0]];
  for(var i=1 ; i<N ; i++){
    acc_values[i] = acc_values[i-1] + values[i]
  }

  const result = Math.max(...acc_values);
  if(result < 0){
    console.log(0);
  }else{
    console.log(result);
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

