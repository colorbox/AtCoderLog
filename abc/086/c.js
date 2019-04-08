function is_possible_trip(prev, next){
  prev_array = prev.split(' ').map(x => parseInt(x));
  next_array = next.split(' ').map(x => parseInt(x));;
  time_distance = next_array[0] - prev_array[0];
  x_distance = next_array[1] - prev_array[1];
  if(x_distance < 0){x_distance = -1*x_distance;}
  y_distance = next_array[2] - prev_array[2];
  if(y_distance < 0){y_distance = -1*y_distance;}
  distance = x_distance + y_distance;
  
  if(distance > time_distance){return false;}
  
  if((time_distance - distance)%2!=0){return false;}
  
  return true;
}

function main(input) {
  input_array = input.split('\n');
  count = input_array[0];
  
  input_array[0]='0 0 0';
  
  for(i=0; i < count;i++){
    if(!is_possible_trip(input_array[i],input_array[i+1])){
      console.log('No');
      return;
    }
  }
  console.log('Yes');
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

