function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines.shift());
  const H = lines.shift().split(' ').map(x => parseInt(x));

  const DP = Array(N).fill(Infinity);
  DP[0]=0;
  DP[1]=Math.abs(H[0]-H[1]);

  for(var i=2;i<N;i++){
    var one_hop = DP[i-1] + Math.abs(H[i-1]-H[i]);
    var two_hop = DP[i-2]+ Math.abs(H[i-2]-H[i]);

    DP[i]=Math.min(one_hop, two_hop);
  }
  //console.log(DP);
  console.log(DP[N-1]);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

