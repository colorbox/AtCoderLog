function main(input){
  const lines = input.split('\n');
  const H = lines[0].split(' ').map(x => parseInt(x))[0];
  const W = lines[0].split(' ').map(x => parseInt(x))[1];

  const wall = lines.slice(1,1+H).map(x => x.split(''));

//    console.log(wall);

  var result = true;
  for(var h = 0;h<H;h++){
    for(var w = 0;w<W;w++){

      var current_hex = wall[h][w];
      if(current_hex=='.'){continue;}

      var up = (h>0 && wall[h-1][w]=='.');
      var down  = (h<H-1 && wall[h+1][w]=='.');
      var left = (w>0 && (wall[h][w-1]=='.'));
      var right = (w<W-1 && (wall[h][w+1]=='.'));

      if(up && down && left && right){
        result=false;
        break;
      }
    }
  }
  if(result){
    console.log('Yes');
  }else{
    console.log('No');
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
