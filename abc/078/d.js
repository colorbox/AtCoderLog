function main(input){
  const lines = input.split('\n');
  const NZW = lines.shift().split(' ').map(x => parseInt(x));
  const N = NZW[0];
  const Z = NZW[1];
  const W = NZW[2];
  const A = lines.shift().split(' ').map(x => parseInt(x));

  // 初期を維持、n-1取る、n取る

  var fetch_n_1 = 0;
  if(N>1){fetch_n_1=Math.abs(A[N-1] - A[N-2]);}
  const fetch_n = Math.abs(A[N-1]-W);

  const result = Math.max(fetch_n_1, fetch_n)
  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
