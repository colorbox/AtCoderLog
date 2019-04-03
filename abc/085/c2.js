function main(input) {
  const input_array = input.split(' ');
  const sum_price = input_array[1];
  const paper_money_count = input_array[0];
  
  for(count_10000=0; count_10000<=paper_money_count ;count_10000++){
    maximum_price = 10000 * count_10000 + 5000 * (paper_money_count - count_10000);
    minimum_price = 10000 * count_10000 + 1000 * (paper_money_count - count_10000);
    if(sum_price > maximum_price || sum_price < minimum_price){
      continue;
    }
    for(count_5000=0; count_5000<=paper_money_count - count_10000 ;count_5000++){
      maximum_price = 10000 * count_10000 + 5000 * (paper_money_count - count_10000) + 1000 * (paper_money_count - count_10000 - count_5000);
      if(sum_price > maximum_price){
        continue;
      }
      for(count_1000=0; count_1000<=paper_money_count - (count_10000 + count_5000) ;count_1000++){
        if(count_10000 + count_5000 + count_1000 != paper_money_count){
          continue;
        }
        if(count_10000 * 10000 + count_5000 * 5000 + count_1000 * 1000 == sum_price){
          console.log(`${count_10000} ${count_5000} ${count_1000}`);
          return;
        }
      }
    }
  }
 
  console.log('-1 -1 -1');
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
