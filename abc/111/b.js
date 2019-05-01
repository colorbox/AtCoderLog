function main(input){
  const n = parseInt(input.trim());

  const abcs = [0,111,222,333,444,555,666,777,888,999];

  for(var i=0;i<9;i++){
    if(abcs[i]<n && n<=abcs[i+1]){
      console.log(abcs[i+1]);
    }
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
