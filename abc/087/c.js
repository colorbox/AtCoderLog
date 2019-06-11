function main(input) {
  const lines = input.split("\n");
  const N = parseInt(lines.shift());

  const upper = lines.shift().split(' ').map(x => parseInt(x));
  const downer = lines.shift().split(' ').map(x => parseInt(x));

  const cum_up = [upper[0]];
  const cum_down = [downer[0]];

  if (N==1){
    console.log(upper[0] + downer[0]);
    return
  }
  for(var i=1;i<N;i++){
    cum_up.push(cum_up[i-1]+upper[i])
    cum_down.push(cum_down[i-1]+downer[i])
  }

  var result = cum_up[0]+cum_down[N-1];
  for(var i=1;i<N;i++){
    var current = cum_up[i]+cum_down[N-1]-cum_down[i-1]
    if (current > result){result = current;}
  }

  console.log(result);

//  console.log(upper);
//  console.log(cum_up);

//  console.log(downer);
//  console.log(cum_down);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
