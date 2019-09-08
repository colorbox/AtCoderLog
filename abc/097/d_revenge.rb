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

n, m = gets.strip.split.map(&:to_i)
ps = gets.strip.split.map(&:to_i)
xy = readlines.map {|line| line.strip.split.map(&:to_i) }

uf = UnionFind.new(n+1)

xy.each do|x, y|
  uf.unite(x,y)
end

result = 0
ps.each_with_index do|p, i|
  ci = i+1
  result += 1 if uf.same_parent?(ci, p)
end

p result
