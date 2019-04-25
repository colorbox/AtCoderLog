
// 配列に全部の島のデータを突っ込む
// 各島はparent,sizeから成る、自分がどの島かはインデックスで判断。

function UnionFind(n){
  this.islands = [];
  for(var i=0; i<n; i++){
    this.islands[i] = {
      parent: i,
      size: 1,
    }
  }
}

UnionFind.prototype.same_group = function(left_index, right_index){
  const right_root = this.root(right_index);
  const left_root = this.root(left_index);
  return (right_root == left_root);
}

UnionFind.prototype.merge_islands = function(left_index, right_index){
  const right_root = this.root(right_index);
  const left_root = this.root(left_index);

  if(right_root.parent==left_root.parent){return 0;}

  left_root.size = left_root.size + right_root.size;
  right_root.parent = left_index;

  return 1;
}

UnionFind.prototype.root = function(index){
  if(this.islands[index].parent == index){
    return this.islands[index];
  }

  var parent_node = this.root(this.islands[index].parent);
  this.islands[index].parent = parent_node.parent;
  return parent_node;
}

UnionFind.prototype.get_size = function(index){
  var root_node = this.root(index);
  return root_node.size;
}

function main(input) {
  const formatted_input = input.split('\n').map( x => x.split(' ').map( x => parseInt(x, 10) ) );
  const N = formatted_input[0][0];
  const M = formatted_input[0][1];
  var reverse_bridges = [];

  for(var i=0;i<M;i++){
    reverse_bridges.push(formatted_input[1+i]);
  }
  reverse_bridges = reverse_bridges.reverse();

  var uf = new UnionFind(N)

  var unconvinience = N*(N-1)/2;
  var results = [unconvinience];

  for(bridge of reverse_bridges){

    left_index = bridge[0]-1
    right_index =  bridge[1]-1

    var diff = uf.get_size((left_index)) * uf.get_size(right_index);

    if(uf.merge_islands(left_index, right_index)==1){
      unconvinience -= diff;
    }
    results.push(unconvinience);
  }

  const reversed_result = results.reverse();

  for(var i = 1; i<=M ; i++){
    console.log(reversed_result[i]);
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

//02:05:00 > 

