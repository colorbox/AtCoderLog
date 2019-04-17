function main(input) {
  const formatted_input = input.split('\n')[0].split('');

  var blue_count=0;
  var red_count=0;

  for( var i=0; i<formatted_input.length ; i++ ){
    if(formatted_input[i]=='0'){
      blue_count++;
    }else{
      red_count++;
    }
  }

  diff = Math.max(blue_count, red_count) - Math.min(blue_count, red_count)

  console.log(formatted_input.length - diff)
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

