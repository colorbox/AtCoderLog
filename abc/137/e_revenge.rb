require 'set'

n, m, tax = gets.strip.split.map(&:to_i)
abc = readlines.map {|line| line.strip.split.map(&:to_i) }
abc = abc.map {|a, b, c| [a, b, -1*(c-tax)] }

graph = Array.new(n+1) { [] }
r_graph = Array.new(n+1) { [] }
abc.each do |a, b, c|
  graph[a] << b
  r_graph[b] << a
end

# get available nodes, and edges
def reachable(s, g)
  q = [s]
  visited = Set.new(q)
  until q.empty?
    c=q.shift
    g[c].each do |to|
      next if visited.include?(to)
      visited.add(to)
      q.push(to)
    end
  end
  visited
end

from_1 = reachable(1, graph)
from_n = reachable(n, r_graph)
available_nodes = from_1 & from_n
edges = abc.select {|a, b, c| available_nodes.include?(a) && available_nodes.include?(b) }

# v-f
INF = 10**12
updated=false
dist = Array.new(n+1, INF)
dist[1]=0
n.times do
  updated = false
  edges.each do |from, to, cost|
    next if dist[from]==INF
    if dist[to] > dist[from] + cost
      dist[to] = dist[from] + cost
      updated=true
    end
  end
  break unless updated
end

if updated
  p -1
  exit
end

# answer
p [-dist[n], 0].max
