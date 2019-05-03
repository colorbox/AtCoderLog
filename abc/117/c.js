function main(input){
  const lines = input.split('\n')
  const N = parseInt(lines[0].split(' ')[0])
  const M = parseInt(lines[0].split(' ')[1])
  const Xs = lines[1].split(' ').map(x => parseInt(x))

  if(M<=N){console.log(0);return;};

  const target_section_count = M-N;
  const sorted_Xs = Xs.sort(function(a,b){return a-b;})
  var section_lengths = [];
  for(var i=0;i<M-1;i++){
    section_lengths.push(sorted_Xs[i+1] - sorted_Xs[i]);
  }

  const sorted_section_lengths = section_lengths.sort(function(a, b){return a-b;})

  var result = 0;
  for(var i=0;i<M-N;i++){
    result += sorted_section_lengths[i]
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
