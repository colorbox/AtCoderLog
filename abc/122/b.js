function main(input) {
  const formatted_input = input.split('\n')[0];
  const S = formatted_input;
 
  var result = 0;
  var tmp = 0;
  for(var i=0;i<S.split('').length;i++){
    var b=S.split('')[i];
 
    if(b=='A' || b=='T' || b=='G' || b=='C'){
      tmp++;
    }else{
      result = Math.max(result, tmp);
      tmp=0;
    }
  }
  result = Math.max(result, tmp);
 
  console.log(result);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

