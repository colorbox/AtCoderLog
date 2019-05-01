function main(input){
  const N=input.trim();
  const S = N.split('');
  var result = [];
  for(var i=0;i<S.length;i++){
    if(S[i]=='9'){
      result.push('1');
    }else{
      result.push('9');
    }
  }
  console.log(result.join(''));
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
