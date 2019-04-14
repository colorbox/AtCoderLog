function main(input) {
  const inputs = input.split('\n');
  const count = parseInt(inputs[0], 10);
  const heights =  inputs[1].split(' ').map(x => parseInt(x, 10));
  const mountains =[]
 
  pre_height = 0;
  for (i=0 ; i<count ; i++){
    //console.log((pre_height <= heights[i]))
    //console.log([pre_height , heights[i]])
    if( pre_height <= heights[i] ){
      mountains.push(heights[i]);
    }
    pre_height = Math.max(pre_height, heights[i])
  }
 
  console.log(mountains.length);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

