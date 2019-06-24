function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines.shift().split(' '));
  const ABC = lines.map(line => line.split(' ').map(x => parseInt(x)) );

//console.log(N);
//console.log(ABC);

  const DP = Array(3);
  DP[0] = Array(N).fill(Infinity);
  DP[1] = Array(N).fill(Infinity);
  DP[2] = Array(N).fill(Infinity);
  DP[0][0]=ABC[0][0];
  DP[1][0]=ABC[0][1];
  DP[2][0]=ABC[0][2];

  for(var i=1;i<N;i++){
    DP[0][i]=ABC[i][0] + Math.max(DP[1][i-1], DP[2][i-1]);
    DP[1][i]=ABC[i][1] + Math.max(DP[0][i-1], DP[2][i-1]);
    DP[2][i]=ABC[i][2] + Math.max(DP[0][i-1], DP[1][i-1]);
  }

//8+8+5+7+8+3+7
//8 16 21 28 36 39 46

//  console.log(DP);
  const result = Math.max(DP[0][N-1], DP[1][N-1], DP[2][N-1]);
  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

