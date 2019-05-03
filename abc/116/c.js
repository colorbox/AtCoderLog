function main(input){
  const lines = input.split('\n');
  const N=parseInt(lines[0]);
  const Hs=lines[1].split(' ').map(x => parseInt(x));

  var result = 0;
  const highest = Math.max(...Hs);
  for(var j=1;j<=highest;j++){
    var previous_high = 0;
    for(var i=0;i<N;i++){
      var current_high = Hs[i];
      if(current_high>=j && previous_high<j){
        result++;
      }
      previous_high=current_high;
    }
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
