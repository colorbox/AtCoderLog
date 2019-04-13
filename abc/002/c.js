function main(input) {
  const dots = input.split('\n')[0].split(' ').map(x =>parseInt(x, 10));

  x = [dots[0], dots[1]];
  y = [dots[2], dots[3]];
  z = [dots[4], dots[5]];

  y = [y[0] - x[0], y[1] - x[1]];
  z = [z[0] - x[0], z[1] - x[1]];

  answer = ( (y[0] * z[1] - y[1]*z[0])/2)

  if(answer < 0){ answer = answer * -1; }
  answer = parseInt(answer * 10, 10)/10;

  console.log(answer);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

