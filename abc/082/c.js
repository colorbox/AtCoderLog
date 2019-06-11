function main(input){
  const lines = input.split('\n');
  const N = parseInt(lines.shift());
  const A = lines.shift().split(' ').map(x => parseInt(x)).sort((l, r)=>l-r);

//  console.log(N);
//  console.log(A);

  var current=A[0];
  var count=1;
  var result=0;
  for(var i=1;i<=A.length;i++){
    if(A[i-1]==A[i]){
      count++;
    }else{
      var diff=count-current;
      if(diff<0){diff+=current;}
      result+=diff
      current=A[i];
      count=1;
    }
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
