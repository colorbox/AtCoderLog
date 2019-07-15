INF=Float::INFINITY
n, m = gets.strip.split.map(&:to_i)
uvl = readlines.map {|line| line.strip.split.map(&:to_i) }.map {|u,v,l| [u,v].minmax.push(l) }

roads = []
n.times { |index| roads.push([INF]*n) }

neighbor_index = []
neighbors = [INF]*n

uvl.each do |u, v, l|
  if (u-1).zero?
    neighbor_index.push(v-1)
    neighbors[v-1]=l
  else
    roads[v-1][u-1] = roads[u-1][v-1]=l
  end
end

if neighbor_index.count<2
  p -1; exit;
end

n.times do |via|
  roads_to_via = roads[via]
  n.times do |from|
    next if from==via
    roads_from = roads[from]

    (from+1..n-1).each do |to|
      direct_cost = roads_from[to]

      via_cost = roads_from[via] + roads_to_via[to]

      roads_from[to] = roads[to][from] = roads[from][to] = via_cost if via_cost < direct_cost
    end
  end
end

result = INF
neighbor_index.combination(2).each do |start, goal|
  s, g = [start, goal].minmax

  result = [result, neighbors[s] + neighbors[g]+roads[s][g]].min
end

if result<INF
  p result
else
  p -1
end
