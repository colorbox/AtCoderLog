function reverse(s) {
  return s.split('').reverse().join('');
}
 
function r_search(input){
  const words = ['dreamer', 'dream', 'eraser', 'erase'];
  const reversed_words = words.map(x => reverse(x));
  var current_input = reverse(input);

  length_check_loop: while(current_input!=""){
    for(word of reversed_words){
      
      if(current_input.startsWith(word)){
        current_input = current_input.substring(word.length)
        continue length_check_loop;
      }
    }
    return false;
  }
  return true;
}
 
function main(input) {
  if(r_search(input.split('\n')[0])){
    console.log('YES');
  }else{
    console.log('NO');
  }
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));

