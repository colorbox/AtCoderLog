ifunction main(input) {
  const formatted_input = input.split(' ').map(x => parseInt(x));
 
  const A = formatted_input[0];
  const B = formatted_input[1];
  const T = formatted_input[2];
 
  var TT = T+0.5;
  TT = TT - TT%A;
 
  var result = (TT/A)*B;
  result = parseInt(result, 10);
 
  console.log(result);
}

