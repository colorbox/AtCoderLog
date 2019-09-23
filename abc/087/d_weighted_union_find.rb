#from https://atcoder.jp/contests/abc087/submissions/4389032

class WeightedUnionFind
  def initialize(size)
    @rank = Array.new(size, 0)
    @parent = Array.new(size, &:itself)
    @weight = Array.new(size, 0)
  end

  def get_parent(id_x)
    if @parent[id_x] == id_x
      id_x
    else
      root = get_parent(@parent[id_x])
      @weight[id_x] += @weight[@parent[id_x]]
      @parent[id_x] = root
    end
  end

  def unite(id_x, id_y, w)
    cw = w + weight(id_x) - weight(id_y)
    x_parent = get_parent(id_x)
    y_parent = get_parent(id_y)
    return if x_parent == y_parent

    if @rank[x_parent] < @rank[y_parent]
      @weight[x_parent] = -cw
      @parent[x_parent] = y_parent
    else
      @weight[y_parent] = cw
      @parent[y_parent] = x_parent

      @rank[x_parent] += 1 if @rank[x_parent] == @rank[y_parent]
    end
  end

  def weight(idx)
    get_parent(idx)
    @weight[idx]
  end

  def weight_diff(x, y)
    weight(y)-weight(x)
  end

  def same_parent?(id_x, id_y)
    get_parent(id_x) == get_parent(id_y)
  end
end

n, m = gets.strip.split.map(&:to_i)
lrd = readlines.map {|line| line.split.map(&:to_i) }

wuf = WeightedUnionFind.new(n+1)

lrd.each do |l, r, d|
  if wuf.same_parent?(l, r)
    if wuf.weight_diff(l, r) != d
      puts 'No'
      exit
    end
  else
    wuf.unite(l, r, d)
  end
end

puts'Yes'
