function main(input){
  const lines = input.split('\n')
  const nums = lines[0].split(' ').map(x => parseInt(x));
  var result = Math.min(nums[0]+nums[1], nums[1]+nums[2], nums[0]+nums[2])

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
