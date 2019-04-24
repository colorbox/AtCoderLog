function union(setA, setB) {
    var _union = new Set(setA);
    for (var elem of setB) {
        _union.add(elem);
    }
    return _union;
}

function create_sets_of_all(islands_count, bridges){
  var islands = [];
  for( var i =0 ; i < islands_count ; i++){
    islands.push(new Set([i+1]));
  }

  for( var i =0 ; i < bridges.length ; i++){
    var unifyied_set = union(islands[bridges[i][0]-1], islands[bridges[i][1]-1]);

    islands[bridges[i][0]-1] = unifyied_set;
    islands[bridges[i][1]-1] = unifyied_set;

    for (var elem of unifyied_set){
      islands[elem-1] = unifyied_set;
    }
  }
  
  return new Set(islands);
}

function inconvenience_for_island(elem, parent_set, set_of_all){
  var result = 0;
  for(var one_set of set_of_all){
    if(one_set == parent_set){continue;}
    for(var element of one_set){
      if(elem<element){result++;}
    }
  }
  return result;
}

function inconvenience(set_of_all){
  if(set_of_all.size == 1){return 0;}
  result = 0;
  for(var set_of_islands of set_of_all){
    for(var island of set_of_islands){
      result += inconvenience_for_island(island, set_of_islands, set_of_all)
    }
  }
  return result;
}

function main(input) {
  const formatted_input = input.split('\n').map( x => x.split(' ').map( x => parseInt(x, 10) ) );

  const N = formatted_input[0][0];
  const M = formatted_input[0][1];
  const bridges = formatted_input.slice(1);

  var initial_inconvenience = inconvenience(create_sets_of_all(N, bridges));

  for(var i=1 ; i<=bridges.length ; i++ ){
      set_of_all = create_sets_of_all(N, bridges.slice(i));
      
      //console.log('---');
      //console.log(initial_inconvenience);
      //console.log(set_of_all);
      console.log(inconvenience(set_of_all)-initial_inconvenience );
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

//02:05:00 > 
