function sort_with_number_count(array){
  var ranks = {};
  for(var i=0;i<array.length;i++){
    if(ranks[array[i]]==undefined){ranks[array[i]]=0;}
    ranks[array[i]]++;
  }

  var array_with_sorted_rank = [];
  const keys = Object.keys(ranks)
  for(var i=0;i<keys.length;i++){
    var key = keys[i];
    array_with_sorted_rank.push([key, ranks[key]]);
  }
  array_with_sorted_rank.sort(function(a, b){return b[1]-a[1];})

  return array_with_sorted_rank.map(x => parseInt(x[0]));
}

function change_count(array, number){

  var result = 0;
  for(var i=0;i<array.length;i++){
    if(array[i]!=number){result++;}
  }
  return result;
}

function main(input){
  const lines = input.split('\n');
  const N=parseInt(lines[0].trim());
  const vs= lines[1].trim().split(' ').map(x => parseInt(x));

  var odds = [];
  var evens = [];
  for(var i=0;i<N;i++){
    if(i%2==0){
      evens.push(vs[i]);
    }else{
      odds.push(vs[i]);
    }
  }

  const odds_sorted_minority  = sort_with_number_count(odds);
  const evens_sorted_minority  = sort_with_number_count(evens);

  var result = 0;
  var odds_first = odds_sorted_minority[0];
  var evens_first = evens_sorted_minority[0];
  if(N==2){
    if(odds_first==evens_first){
      result = 1;
    }
  }else{

    if(odds_first==evens_first){

      var evens_second = evens_sorted_minority[1];
      if(evens_second==undefined){evens_second = evens_first+1;}

      var odd_first_even_second = change_count(odds, odds_first) + change_count(evens, evens_second)

      var odds_second = odds_sorted_minority[1];
      if(odds_second==undefined){odds_second = odds_first+1;}
      var odd_second_even_first = change_count(odds, odds_second) + change_count(evens,  evens_first)

      result = Math.min(odd_first_even_second, odd_second_even_first);
    }else{
      result = change_count(odds, odds_first) + change_count(evens, evens_first);
    }
  }

  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
