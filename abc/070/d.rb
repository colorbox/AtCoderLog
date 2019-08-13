n = gets.strip.to_i
abc = (n-1).times.map { gets.strip.split.map(&:to_i) }
q, k = gets.strip.split.map(&:to_i)
xy = readlines.map {|line| line.strip.split.map(&:to_i) }

graph = Array.new(n+1) { [] }
abc.each do |s, g, cost|
  graph[s] << [g, cost]
  graph[g] << [s, cost]
end

#p graph

def tree_distance_from(start, graph)
  distance = Array.new(graph.length, -1)

  q = [[start, 0]]

  until q.empty? do
    current, current_cost = q.shift
    distance[current] = current_cost
    graph[current].each do |to, cost|
      q << [to, current_cost + cost] if distance[to] == -1
    end
  end

  distance
end

distance_from_k = tree_distance_from(k, graph)

xy.each do|x, y|
  p distance_from_k[x]+distance_from_k[y]
end
