function main(input) {
  const formatted_input = input.split('\n').map(x => parseInt(x));

  const N = formatted_input[0];
  var necks = [];
  for(var i=1;i<=5;i++){
    necks.push(formatted_input[i]);
  }
  const bottle_neck = Math.min(...necks);
  var bottle_neck_time = Math.floor(N/bottle_neck);
  if(N%bottle_neck>0){bottle_neck_time++;}

  var result = 4 + bottle_neck_time;

//  console.log(N);
//  console.log(bottle_neck);
//  console.log(bottle_neck_time);
  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
