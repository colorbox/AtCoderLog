function main(input) {
  const formatted_input = input.split('\n').map( x => x.split(' ').map( x => parseInt(x, 10) ) );


  const first = formatted_input[0];
  const N = first[0];
  const M =first[1]; 
  const X = first[2];
  const Y = first[3];

  const Xs = formatted_input[1];
  const Ys = formatted_input[2];

  var max_x = -101;
  for(var x of Xs){ max_x = Math.max(x, max_x);}
  max_x = Math.max(X, max_x);

  var min_y = 101;
  for(var y of Ys){ min_y = Math.min(y, min_y);}
  min_y = Math.min(Y, min_y);

  if(max_x < min_y){
    console.log('No War');
  }else{
    console.log('War');
  }

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

