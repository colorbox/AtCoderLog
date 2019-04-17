const flatten = (array) => {
    return array.reduce((a, c) => {
        return Array.isArray(c) ? a.concat(flatten(c)) : a.concat(c);
    }, []);
};

function max_array(arr){
  ret = 0;
  for( var i=0 ; i<arr.length ; i++ ){
    ret = Math.max(ret, arr[i]);
  }
  return ret;
}

function has_relation(left, right, relations){
  for( var i=0 ; i<relations.length ; i++){
    if (Math.max(relations[i][0], relations[i][1])==Math.max(left, right) && Math.min(relations[i][0], relations[i][1])==Math.min(left, right)){return true;}
  }
  return false;
}

function diff_seq_arr(arr){
  ret = []
  for( var i=0 ; i<arr.length ; i++ ){
    var modified_arr = arr.slice(i, arr.length);
    modified_arr.push(arr.slice(0, i))
    ret.push(flatten(modified_arr))
  }
  return ret
}

// wrong pattern with wrong diff_seq_arr
//function diff_seq_arr(arr){
//  ret = []
//  for( var i=0 ; i<arr.length ; i++ ){
//    ret.push(arr.slice(i, arr.length))
//  }
//  return ret
//}

function make_faction(faction, target, group, relations){

  if(target == null){
    faction_counts = diff_seq_arr(group).map( new_group =>
      make_faction([], new_group[0], new_group.slice(1), relations)
    )

//console.log(faction_counts);


    return max_array(faction_counts);
  }

  if( faction.length==0 || faction.map( x => has_relation(x, target, relations) ).every( x => x ) ){
    new_faction = faction.slice()
    new_faction.push(target)

    if(group.length==0){return new_faction.length}

    faction_counts = diff_seq_arr(group).map( new_group =>
      make_faction(new_faction, new_group[0], new_group.slice(1), relations)
    )


    return max_array(faction_counts);
  }else{

    return faction.length;
  }
}

function main(input) {
  const inputs = input.split('\n').map( x => x.split(' ').map( x => parseInt(x, 10)) );
  const N = inputs[0][0];
  const M = inputs[0][1];
  const relations = inputs.slice(1);

  var group = [];
  for( var i=0 ; i<N ; i++ ){group.push(i+1);}

  answer = make_faction([], null, group, relations)

  console.log(answer);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

