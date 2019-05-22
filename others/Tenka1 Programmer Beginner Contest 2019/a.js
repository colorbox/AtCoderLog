function main(input) {
  const formatted_input = input.split('\n')[0].split(' ').map( x => parseInt(x, 10) );

  const A = formatted_input[0];
  const B = formatted_input[1];
  const C = formatted_input[2];

  if( (A<C && C<B) || (A>C && C>B) ){
    console.log('Yes');
  }else{
    console.log('No');
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
// 01:34:40 >
