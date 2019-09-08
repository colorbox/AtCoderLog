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


n = gets.strip.to_i
xy = readlines.map {|line| line.strip.split.map(&:to_i) }
xy=xy.uniq

nodes = {}
xy.each_with_index do|(x, y), i|
  nodes[[x, y].to_s] = i+1
end

edges = []
x_order = xy.dup.sort_by(&:first)
x_order.each_cons(2) do |from, to|
  x1, y1 = from
  x2, y2 = to
  from_node = nodes[from.to_s]
  to_node = nodes[to.to_s]
  cost = [(x1-x2).abs, (y1-y2).abs].min

  edges << [from_node, to_node, cost]
end

y_order = xy.dup.sort_by(&:last)
y_order.each_cons(2) do |from, to|
  x1, y1 = from
  x2, y2 = to
  from_node = nodes[from.to_s]
  to_node = nodes[to.to_s]
  cost = [(x1-x2).abs, (y1-y2).abs].min

  edges << [from_node, to_node, cost]
end

edges = edges.sort_by(&:last)
uf = UnionFind.new(n+1)
result=0
edges.each do |from, to, cost|
  next if uf.same_parent?(from, to)

  uf.unite(from, to)
  result+=cost
end

#p x_order
#p y_order

p result
