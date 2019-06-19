function main(input){
  const nums = input.split(' ').map(x => parseInt(x));
  if(nums[0]<nums[1]){
    console.log(0);
  }else{
    console.log(10);
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
