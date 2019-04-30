function main(input) {
  const formatted_input = input.split('\n').map(x => parseInt(x));

  var tmp_minimum=0;
  var result = 0;
  for(var i = 0;i<5;i++){
    result+=(formatted_input[i] - formatted_input[i]%10)
    if(formatted_input[i]%10!=0){
      if(tmp_minimum==0){
        tmp_minimum=formatted_input[i]%10
      }else{
        result+=10;
        tmp_minimum=Math.min(tmp_minimum,formatted_input[i]%10)
      }
    }
  }
  result+=tmp_minimum;

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
