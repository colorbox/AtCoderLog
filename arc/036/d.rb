#from https://atcoder.jp/contests/arc036/submissions/4196978

class UnionFind
  def initialize(size)
    @rank = Array.new(size, 0)
    @parent = Array.new(size, &:itself)
  end

  def unite(id_x, id_y)
    x_parent = get_parent(id_x)
    y_parent = get_parent(id_y)
    return if x_parent == y_parent

    if @rank[x_parent] > @rank[y_parent]
      @parent[y_parent] = x_parent
    else
      @parent[x_parent] = y_parent
      @rank[y_parent] += 1 if @rank[x_parent] == @rank[y_parent]
    end
  end

  def get_parent(id_x)
    @parent[id_x] == id_x ? id_x : (@parent[id_x] = get_parent(@parent[id_x]))
  end

  def same_parent?(id_x, id_y)
    get_parent(id_x) == get_parent(id_y)
  end
end

n, q = gets.strip.split.map(&:to_i)
wxyz = readlines.map {|line| line.strip.split.map(&:to_i) }.map {|w, x, y, z| [w, x, y, z%2] }

uf = UnionFind.new(2*n+2)
wxyz.each do |w, x, y, z|
  if w==1
    if z.even?
      uf.unite(x, y)
      uf.unite(x+n, y+n)
    else
      uf.unite(x, y+n)
      uf.unite(x+n, y)
    end
  else
    puts uf.same_parent?(x, y) ? 'YES' : 'NO'
  end
end
