const divider = 1e9+7;

var _fibs = [0, 1];
function fib(n) {
  for(var i = _fibs.length; i <= n; i++){
    _fibs[i] = (_fibs[i-1]%divider + _fibs[i-2]%divider)%divider;
  }
}

function fibs(n) {
  if(n<=0){return 1;}
  fib(n);
  return _fibs.slice(n, n + 1)[0];
}

function main(input){
  const lines = input.split('\n')
  const N_M = lines.shift().split(' ').map(x => parseInt(x));
  const N = N_M[0];
  const M = N_M[1];
  const A = []
  for(var i=0;i<M;i++){
    A.push(parseInt(lines.shift()));
  }

  if(M>1){
    for(var i=1;i<M;i++){
      if(A[i]-A[i-1]==1){
        console.log(0);
        return;
      }
    }
  }

  const diffs = [];
  A.unshift(-1);
  A.push(N+1);

  for(var i=1;i<M+2;i++){
    diffs.push(A[i]-A[i-1]-1)
  }

  var result = 1;

  for(diff of diffs){
//    console.log([result,diff,fibs(diff)]);
    result = (result * fibs(diff))%divider;
  }
  result = result%divider;

//  console.log(diffs);
  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

// JSの精度の問題から、ACできない
// 下記のような入力例でわかる
//```
// 8004 4
// 2000
// 4001
// 6002
// 8003
// ```
// 141828449^2%divider は`804938445`とならなければならないが、これでやると`804938444`となる。
//
