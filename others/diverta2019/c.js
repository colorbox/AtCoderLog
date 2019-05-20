function ab_count(array){
  var result=0;
  for(var i=0;i<array.length-1;i++){
    if(array[i]=='A' && array[i+1]=='B'){result++;}
  }
  return result;
}

function main(input){
  const lines = input.split('\n');
  const N = lines[0].split(' ').map(x => parseInt(x))[0];
  lines.shift();
  const S = lines;

  var result = 0;
  var head=0;
  var tail=0;
  var sum=0;
  for(var i=0;i<N;i++){
    var current_s = S[i].split('');
    if(current_s[0]=='B'){head++;}
    if(current_s[current_s.length-1]=='A'){tail++;}
    if(current_s[0]=='B' || current_s[current_s.length-1]=='A'){sum++;}
    result += ab_count(current_s);
//    console.log([current_s,ab_count(current_s)]);
  }
  const addition = Math.min(tail,head, Math.max(0,sum-1));

  console.log(result+addition);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
