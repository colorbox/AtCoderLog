function get_deg(deg){
  deg_array = ['N', 'NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE', 'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW']
  deg_num = parseInt((1 + (deg - 1125)/2250));
  if(deg < 1125){deg_num = 0;}
  if(deg_num  > 15){deg_num = 0}
  return deg_array[deg_num];
}

function get_dis(dis){
  dis_ranges = [
    [0.0,0.2],
    [0.3,1.5],
    [1.6,3.3],
    [3.4,5.4],
    [5.5,7.9],
    [8.0,10.7],
    [10.8,13.8],
    [13.9,17.1],
    [17.2,20.7],
    [20.8,24.4],
    [24.5,28.4],
    [28.5,32.6]
  ];
    
  dis_per_s = Math.round(dis/60 * 10) / 10;
  for(i=0;i<12;i++){
    ranges = dis_ranges[i]
    if(ranges[0] <= dis_per_s && dis_per_s <= ranges[1]){
      return i;
    }
  }
  return 12;
}

function main(input) {
  const info = input.split(' ');
  deg = parseInt(info[0], 10);
  dis = parseInt(info[1], 10);

  if(get_dis(dis)==0){
    console.log('C 0')
    return 
  };

  console.log(`${get_deg(deg*10)} ${get_dis(dis)}`)
  
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

