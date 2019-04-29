function gcd(a,b){
  if(b==0){return a;}
  return gcd(b, a%b);
}

function main(input) {
  const formatted_input = input.split('\n');

  const N = parseInt(formatted_input[0], 10);
  const As = formatted_input[1].split(' ').map(x => parseInt(x));

  var L = [];
  var R = [];
  var l_tmp = 0;
  var r_tmp = 0;
  for( var i = 0 ; i<N ; i++ ){
    l_tmp = gcd(l_tmp, As[i]);
    r_tmp = gcd(r_tmp, As[N-1-i]);
    L.push(l_tmp);
    R.push(r_tmp);
  }
  R = R.reverse();

  var results = [];
  for( var i = 0 ; i < N ; i++ ){
    if(i==0){
      results.push(R[i+1]);      
    }else if(i==N-1){
      results.push(L[i-1]);      
    }else{
      results.push(gcd(L[i-1],R[i+1]));
    }
  }

  console.log(Math.max(...results));
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

