function main(input) {
  const formatted_input = input.split('\n');
  const N =  parseInt(formatted_input[0].split(' ')[0]);
  const M =  parseInt(formatted_input[0].split(' ')[1]);
  const C =  parseInt(formatted_input[0].split(' ')[2]);
  const Bs = formatted_input[1].split(' ').map(x => parseInt(x));

  As=[];
  for(var i=0;i<N;i++){
    var tmp_as = formatted_input[2+i].split(' ').map(x => parseInt(x))
    As.push(tmp_as);
  }

//  console.log(N);
//  console.log(M);
//  console.log(C);
//  console.log(Bs);
//  console.log(As);


  var result = 0;

  for(var i=0;i<N;i++){
    var tmp_sum = C;
    for(var j=0;j<M;j++){
      tmp_sum += Bs[j] * As[i][j];
    }

    if(tmp_sum>0){result++;}
  }

  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

