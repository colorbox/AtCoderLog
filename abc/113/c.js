function zero_padding_number(num){
  return ('000000' + num.toString()).slice(-6);
}

function main(input){
  const lines = input.split('\n');
  const N =parseInt(lines[0].split(' ')[0]);
  const M =parseInt(lines[0].split(' ')[1]);
  var pys = [];
  for(var i=0;i<M;i++){
    var line = lines[1+i].split(' ').map(x => parseInt(x))
    pys.push([i, line[0],line[1]]);
  }

  var p_y_sorted = pys.sort(function(a,b){
    if(a[1]==b[1]){return a[2]-b[2];}
    return a[1]-b[1];
  })

  var current_p=0;
  var current_city_index=1;
  for(var i=0;i<p_y_sorted.length;i++){
    var current_city = p_y_sorted[i];
    if(current_p!=current_city[1]){
      current_p=current_city[1]
      current_city_index=1;
    }
    var id = zero_padding_number(current_city[1])+zero_padding_number(current_city_index);
    p_y_sorted[i].push(id);
    current_city_index++;
  }

  const stdin_sorted_cities = p_y_sorted.sort(function(a,b){return a[0]-b[0];})
  for(var i=0;i<M;i++){
    console.log(stdin_sorted_cities[i][3])
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
