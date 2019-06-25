function main(input){
  const lines = input.split('\n');
  const NW = lines.shift().split(' ').map(x => parseInt(x));
  const N = NW[0]
  const W = NW[1]
  const items = lines.map(line => line.split(' ').map(x => parseInt(x)));

  const first = items.shift();
  const first_weight = first[0];
  const first_value = first[1];
  var value_sum = first_value;
  dp = [0]

  for(var i=1;i<=value_sum;i++){
    dp[i]=first_weight;
  }

  for(var i=0;i<items.length;i++){
    var current_weight = items[i][0];
    var current_value = items[i][1];
    value_sum += current_value;

    //console.log(dp);

    //valueがcurrent_value以上なら、合算weightを入れられる
    //合算weightはその前のマスにある値(weight)とcurrent_weightを足したもの

    //その時、今のマス目を見みて入れ方を変える
    //今のマス目インデックス(value)に何もなければcurrent_weightをそのまま入れる、
    // 今のマス目に何かあれば、前のマス目の値(weight)とcurrent_weightを足したものとで値(weight)を比較、低い方を入れる。

    // current_valueがvalue未満ならcurrent_weightを入れるが、マス目に値があるかどうかで分岐する。
    // マス目に何も入っていなければcurrent_weightを入れる
    // なにか入っていれば比較を行い、軽い方を入れる。

    //そのインデックスになにかある、かつcurrent_valueがvalueよりも大きいとそのvalueはそこに入らないので、そのままにしておく

    for(var value=value_sum;value>0;value--){

      if(value >= current_value){
        var prev_weight = dp[value - current_value];
        if(dp[value]==undefined){
          dp[value] = current_weight + prev_weight;
        }else{
          dp[value] = Math.min(prev_weight+current_weight, dp[value]);
        }
      }else{
        if(dp[value]==undefined){
          dp[value]=current_weight;
        }else{
          dp[value]=Math.min(current_weight, dp[value]);
        }
      }
    }
  }


  var result = 0;

  for(var i=dp.length-1;i>=0;i--){
    if(dp[i]<=W){
      result = i;
      break;
    }
  }

  //console.log(dp);

//  console.log(result==90);
  console.log(result);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
