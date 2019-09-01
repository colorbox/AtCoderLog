require 'set'

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

n, k, l  = gets.strip.split.map(&:to_i)
pq = k.times.map { gets.strip.split.map(&:to_i) }
rl = l.times.map { gets.strip.split.map(&:to_i) }

roads = UnionFind.new(n+1)
rails = UnionFind.new(n+1)


pq.each do |p, q|
  roads.unite(p, q)
end

rl.each do |r, l|
  rails.unite(r, l)
end

counter = {}

(1..n).each do |i|
  counter[[rails.get_parent(i), roads.get_parent(i)]] ||= []
  counter[[rails.get_parent(i), roads.get_parent(i)]] << i
end

ans = Array.new(n+1, 0)

counter.values.each do |varr|
  varr.each do |i|
    ans[i] = varr.size
  end
end

ans.shift

puts ans.join(' ')
