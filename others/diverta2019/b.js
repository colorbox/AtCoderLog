function main(input){
  const lines = input.split('\n');
  const R = lines[0].split(' ').map(x => parseInt(x))[0];
  const G = lines[0].split(' ').map(x => parseInt(x))[1];
  const B = lines[0].split(' ').map(x => parseInt(x))[2];
  const N = lines[0].split(' ').map(x => parseInt(x))[3];

  var result = 0;
  const R_limit=Math.max(Math.ceil(N/R),1);
  const G_limit=Math.max(Math.ceil(N/G),1);
  const B_limit=Math.max(Math.ceil(N/B),1);
  for(var r=0;r<=R_limit;r++){
    for(var g=0;g<=G_limit;g++){
      if(r*R + g*G>N){break;}
      if((N-(r*R + g*G))%B==0){result++;}
//        if((N-(r*R + g*G))%B==0){console.log([r,g,(N-(r*R + g*G))/B]);}
    }
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
