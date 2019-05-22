'use strict'

function _xor(a,b){
  let sa = a.toString(2);
  let sb = b.toString(2);
  if(sa.length < sb.length){
    sa = ('0000000000000000000000000000000000000000000000000000000000000000000000'+sa).slice(-sb.length);
  }else if(sa.length > sb.length){
    sb = ('0000000000000000000000000000000000000000000000000000000000000000000000'+sb).slice(-sa.length);
  }


  let answer = 0;
  let bi = 1;
  for(let i=sa.length-1;i>=0;i--){
    if((sa[i]==="0"&&sb[i]==="1")||(sa[i]==="1"&&sb[i]==="0")){
      answer += bi;
    }
    bi *= 2;
  }
  return answer;
}

function xor(a,b){
  const m = 10000000;
  var tmp_up = (parseInt(a/m)^parseInt(b/m))*m;
  var tmp_down = (a%m)^(b%m);

  if(a<m && b<m){return tmp_down;}
  if(a<m){tmp_up = parseInt(b/m)*m;}
  if(b<m){tmp_up = parseInt(a/m)*m;}

  return tmp_down+tmp_up;
}

function acc_xor(n){
  if(n<=0){return 0;}
  if(n%4==0){
    return xor(0,n);
  }
  if(n%4==1){
    return 1;
  }
  if(n%4==2){
    return xor(1,n);
  }
  if(n%4==3){
    return 0;
  }

}

function main(input) {
  const formatted_input = input.split('\n');
  const A =  parseInt(formatted_input[0].split(' ')[0]);
  const B =  parseInt(formatted_input[0].split(' ')[1]);

  const acc_a = acc_xor(A-1);
  const acc_b = acc_xor(B);
  const result = _xor(acc_a, acc_b)
//  console.log([A,B]);
//  console.log([acc_a,acc_b]);
//  console.log(_xor(B,0))
  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

