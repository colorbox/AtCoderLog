function main(input){
  const lines = input.split('\n');

  const HW = lines.shift().split(' ').map(x => parseInt(x));
  const H = HW[0];
  const W = HW[1];
  const C = [];
  for(var i=0;i<10;i++){
    C.push( lines.shift().split(' ').map(x => parseInt(x)) );
  }
  const A = [];
  for(var i=0;i<H;i++){
    A.push( lines.shift().split(' ').map(x => parseInt(x)) );
  }

//console.log(H);
//console.log(W);
//console.log(C);
//console.log(A);

  for(var k=0;k<10;k++){
    for(var i=0;i<10;i++){
      for(var j=0;j<10;j++){
        C[i][j] = Math.min(C[i][j], C[i][k] + C[k][j]);
      }
    }
  }

//console.log(C);

  var result = 0;
  for(var i=0;i<H;i++){
    for(var j=0;j<W;j++){
      var current_from = A[i][j];
      if(current_from >= 0){
        //console.log([current_from,C[current_from][1],i]);
        result += C[current_from][1];
      }
    }
  }

  console.log(result);


}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
