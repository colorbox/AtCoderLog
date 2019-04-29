function main(input) {
  const formatted_input = input.split('\n');
  const N =  parseInt(formatted_input[0].split(' ')[0]);
  const M =  parseInt(formatted_input[0].split(' ')[1]);

  As=[];
  for(var i=0;i<N;i++){
    var tmp_as = formatted_input[1+i].split(' ').map(x => parseInt(x))
    As.push(tmp_as);
  }

  var sorted_As = As.sort(function(a, b){
    return a[0]-b[0];
  })

//  console.log(N);
//  console.log(M);
//  console.log(As);
//  console.log(sorted_As);

  var result = 0;
  var tmp_count = 0;
  for(var i = 0;i<N;i++){
    var shortage = M-tmp_count;
    if(sorted_As[i][1] >= shortage){
      result += sorted_As[i][0]*shortage;
      break;
    }else{
      tmp_count+=sorted_As[i][1];
      result += sorted_As[i][0] * sorted_As[i][1];
    }
  }
  

  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

