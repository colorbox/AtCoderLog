function main(input) {
  const inputs = input.split('\n');
  const counts = inputs[0].split(' ').map( x => parseInt(x, 10) );
 
  const n = counts[0];
  const k = counts[1];
 
  const input_numbers = inputs[1].split('').map( x => parseInt(x, 10) );
 
if(n==1){
  console.log(1);
  return;
}
 
  var compressed_numbers = [];
  if(input_numbers[0]==0){compressed_numbers=[0];}
 
  var pre_count = 1;
  var pre_number=input_numbers[0];
 
  pre_numbers = [input_numbers[0]];
  for(var  i=1 ; i<n ; i=i+1){
    if(pre_number!=input_numbers[i]){
      compressed_numbers.push(pre_count);
      pre_count = 1;
      pre_number = input_numbers[i]
    }else{
      pre_count = pre_count+1;
    }
  }
  compressed_numbers.push(pre_count);
 
  var accumulation_sum_array = [0];
  for(var i=0;i<compressed_numbers.length;i++){
    accumulation_sum_array[i+1] = accumulation_sum_array[i] + compressed_numbers[i]
  }
 
//console.log(compressed_numbers);
//console.log(accumulation_sum_array);
 
  var answer=0;
  var sub_array=[];
  const a_a_length = accumulation_sum_array.length;
  const fetch_count = k*2+1;
  for(var  i=0 ; i<compressed_numbers.length ; i+=2){
    // k * 2 + 1 要素をとってくる
    if( i+fetch_count > a_a_length-1 ){
      answer = Math.max(accumulation_sum_array[a_a_length-1] - accumulation_sum_array[i], answer)
    } else {
      answer = Math.max(accumulation_sum_array[i+fetch_count] - accumulation_sum_array[i], answer)
    }
  }
 
  console.log(answer);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

