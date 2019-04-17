function search_nums(left, right){// left < right
  nums = [];
  for( var i=0 ; i<left ; i++ ){
    num = left-i;
    if((left%num==0) && (right%num==0)){
      nums.push(num);
    }
  }
  return nums;
}

function main(input) {
  const formatted_input = input.split(' ').map( x => parseInt(x, 10) );
  const A = formatted_input[0];
  const B = formatted_input[1];
  const K = formatted_input[2];



  if(A <= B){
    console.log(search_nums(A, B)[K-1]);
  }else{
    console.log(search_nums(B, A)[K-1]);
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

