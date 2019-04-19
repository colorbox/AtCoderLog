function main(input) {
  const formatted_input = input.split('\n');

  const before = formatted_input[0].split('');
  const after = formatted_input[1].split('');

  var before_hash = {};
  for(var elem of before){
    before_hash[elem] = new Array;
  }

  var after_hash = {};
  for(var elem of after){
    after_hash[elem] = new Array;
  }

  
  var i=0
  for( var elem of before ){
    var arr = before_hash[elem];
    arr.push(i);
    before_hash[elem] = arr;
    i++;
  }

  var i=0
  for( var elem of after ){
    var arr = after_hash[elem];
    arr.push(i);
    after_hash[elem] = arr;
    i++;
  }

 before_arr = []
 for(var elem in before_hash){
   var arr = before_hash[elem];
   for(var i=0; i < arr.length ; i++ ){
     before_arr.push(arr[i]);
   }
    before_arr.push('|');
 }

  after_arr = []
  for(var elem in after_hash){
    var arr = after_hash[elem];
    for(var i=0; i < arr.length ; i++ ){
      after_arr.push(arr[i]);
    }
    after_arr.push('|');
  }

  //console.log(before_hash);
  //console.log(after_hash);
  //console.log(before_arr);
  //console.log(after_arr);
  
  if(after_arr.toString()==before_arr.toString()){
    console.log('Yes');
  }else{
    console.log('No');
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
// 01:34:40 > 

