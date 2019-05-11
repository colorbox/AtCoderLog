function filter_evens(numbers){
  return numbers.filter(x => x%2==0)
}

function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines[0]);
  var As = lines[1].split(' ').map(x => parseInt(x));

  // Aの配列から偶数を取り出して、その個数を数える
  // 残った配列を2で割って、偶数をを数える、あとはこの繰り返し
  As = filter_evens(As);
  var result = As.length;
  while(As.length > 0){
    As = As.map(x => x/2).filter(x => !(x-Math.floor(x)>0));
    As = filter_evens(As);
    result += As.length;
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
