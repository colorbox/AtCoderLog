function main(input){
  const S = input.split('\n')[0].split('');
  const K = parseInt(input.split('\n')[1]);

  for(var i=0;i<S.length && i<K;i++){
    console.log(S[i])
    if(S[i]!='1'){
//      console.log(S[i]);
      return;
    }
  }
  console.log(1);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
