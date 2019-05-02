function convert_753_from_4b(based3){
  const str = based3.split('')
  var result = '';
  for(var i=0;i<str.length;i++){
    if(str[i]=='3'){result+='7'}
    if(str[i]=='2'){result+='5'}
    if(str[i]=='1'){result+='3'}
    if(str[i]=='0'){result+='0'}
  }
  return parseInt(result);
}

function generate_753_number(number){
  if(n.length==10){return n}
  return [generate_753_number(number + '3'),generate_753_number(number + '5'),generate_753_number(number + '7')]
}

function is_753(number){
  return (number==3 || number==5 || number==7)
}

function is_753_number(n){
  const splitted = n.toString().split('');
  const numbers = new Set(splitted);
  if(numbers.size!=3){return false;}

  return numbers.has('3') && numbers.has('5') && numbers.has('7')
}

function main(input){
  const N = parseInt(input.trim());

  var result=0;
  for(var i=0;i<=1048569;i++){
    var based4 = i.toString(4);
    var num_753 = convert_753_from_4b(based4);

    if(num_753>N){break;}

//console.log([i,based4,num_753])

    if(is_753_number(num_753)){
      result++;
      //console.log(num_753);
    }
  }


  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin','utf8'))
