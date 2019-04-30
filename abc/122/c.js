function main(input) {
  const formatted_input = input.split('\n');
  const N = parseInt(formatted_input[0].split(' ')[0]);
  const Q = parseInt(formatted_input[0].split(' ')[1]);
  const S = formatted_input[1].split('');


//console.log([N,Q,S])

  var acc_arr = [0];
  var count = 0;
  for(var i=1;i<S.length;i++){
    var b=S[i-1];
    var b_1 = S[i];
    if(b=='A' && b_1=='C'){
      count++;
    }
    acc_arr.push(count);
  }

  //console.log(acc_arr);


  for(var i=0;i<Q;i++){
    var l = parseInt(formatted_input[2+i].split(' ')[0])
    var r = parseInt(formatted_input[2+i].split(' ')[1])

    console.log(acc_arr[r-1] - acc_arr[l-1])
  }

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

