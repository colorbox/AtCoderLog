function devaluation(time){
  minutes = time%100
  return (time - minutes%5)
}

function provaluation(time){
  hour = parseInt(time/100, 10);
  minutes = time%100
  
  if(minutes%5==0){return time;}

  if(minutes > 55){return (hour+1)*100}
  
  return hour*100 + minutes + (5-minutes%5)
}

function make_4(time){
  if(time.toString().length == 1){
    return `000${time}`
  }else if(time.toString().length == 2){
    return `00${time}`
  }else if(time.toString().length == 3){
    return `0${time}`
  }
  return `${time}`
}

function main(input) {
  const info = input.split('\n');
  count = parseInt(info[0], 10);
  
  input_ranges = [];
  for(i=1;i<=count;i++){
    ranges = info[i].split('-').map(x => parseInt(x));

    input_ranges.push(ranges);
  }

  for(i=0;i<count;i++){
    input_ranges[i] = [devaluation(input_ranges[i][0]), provaluation(input_ranges[i][1])]
  }
  
  //console.log(input_ranges)

  rain_range = new Array(24)
  for(i=0;i<24;i++){
    rain_range[i]= new Array(12).fill(0)
  }

  for(i=0;i<count;i++){
    start_time = input_ranges[i][0]
    end_time = input_ranges[i][1]

    for(hour=0;hour<24;hour++){
      for(minute=0;minute<12;minute++){
        current = (hour*100 + minute*5)

        if(start_time <= current && current < end_time && rain_range[hour][minute] == 0){
          //console.log(`${start_time} < ${current} < ${end_time}`)
          
          rain_range[hour][minute] = 1
        }
      }
    }
  }
  
  //console.log(rain_range)

  printing = false;
  start = ''
  end = ''
  for(hour=0;hour<24;hour++){
    for(minute=0;minute<12;minute++){
      
      current = rain_range[hour][minute]
      if(current==1 && !printing){
        start = (hour*100 + minute*5).toString();
        printing = true;
      }
      end = (hour*100 + minute*5).toString();
      if(printing && current==0){
        console.log(`${make_4(start)}-${make_4(end)}`)
        printing = false;
        start = ''
      }
    }
  }
  if(printing){
    console.log(`${make_4(start)}-2400`)
  }

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

