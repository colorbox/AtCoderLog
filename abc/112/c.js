function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines[0]);
  var vs = [];
  for(var i=0;i<N;i++){
    var line = lines[i+1].split(' ').map(x => parseInt(x));
    vs.push(line);
  }

  if(N==1){
    console.log(vs[0].join(' '));
    return;
  }

  const one_vs = vs.filter(v => v[2]>0);
  if(one_vs.length==1){
    console.log(one_vs[0].join(' '));
    return;
  }


  var candidates = [];
  for(var x=0;x<=100;x++){
    for(var y=0;y<=100;y++){
      var one_v = one_vs[0];
      var height = Math.abs(x - one_v[0]) + Math.abs(y - one_v[1]) + one_v[2]
      candidates.push([x,y,height]);
    }
  }

//console.log(candidates);

  var highest = [0,0,0];
  for(var j=0;j<candidates.length;j++){
    var candidate = candidates[j];
    var detected=true;
    for(var i=0;i<one_vs.length;i++){
      var one_v = one_vs[i];
      var tmp_height = Math.abs(candidate[0] - one_v[0]) + Math.abs(candidate[1] - one_v[1]) + one_v[2];
      if(candidate[2]!=tmp_height){detected=false;}
    }
    if(detected && candidate[2] > highest[2]){highest = candidate}
  }
  console.log(highest.join(' '));
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
