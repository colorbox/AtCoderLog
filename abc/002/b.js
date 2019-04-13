function is_not_vowel(str){
  return (str!='a' && str!='i' && str!='u' && str!='e' && str!='o');
}

function main(input) {
  const voice = input.split('\n')[0].split('').filter(x => is_not_vowel(x)).join('');

  console.log(voice);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

