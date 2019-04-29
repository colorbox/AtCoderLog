function main(input) {
  const formatted_input = input.split('\n');

  const N = parseInt(formatted_input[0], 10);
  const As = formatted_input[1].split(' ').map(x => parseInt(x));
  var edited_As = []
  var minus = As.filter(x => x<=0);
  var abs = As.map(x => Math.abs(x))
  var result = 0;
  for(var i=0;i<N;i++){
    var tmp = As[i];
    if(tmp<0){tmp = tmp*-1;}
    result += tmp;
  }

  if(minus.length%2==1){
    var min_value = Math.min(...abs);
    result = result - 2*Math.abs(min_value);
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

