function main(input) {
  const info = parseInt(input, 10);
  
  if(info < 100){
    console.log('00');
  }else if(info <= 5000){
    result = info * 10 / 1000

    if(result < 10){
      console.log(`0${result}`)
    }else{
      console.log(`${result}`)
	}
  }else if(info <= 30000){
    result = info / 1000 + 50
    
      console.log(`${result}`)
  }else if(info <= 70000){
    result = ((info - 30000)/5 + 80000)/1000

    console.log(result);
  }else if(info > 70000){
    console.log('89');
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

