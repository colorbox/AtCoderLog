# from https://atcoder.jp/contests/abc035/submissions/6420550

n, m, t = gets.strip.split.map(&:to_i)
aa = gets.strip.split.map(&:to_i)
abc = readlines.map {|line| line.strip.split.map(&:to_i) }

graph = Array.new(n+1) { [] }
r_graph = Array.new(n+1) { [] }
abc.each do |a, b, c|
  graph[a] << [b,c]
  r_graph[b] << [a, c]
end

def dijkstra(s, g, n)
  dist = [10**15]*(n+1)
  dist[s]=0
  q = [[s,0]]

  until q.empty?
    from, cost = q.shift

    next if dist[from] < cost
    dist[from] = cost

    g[from].each do |to, c|
      nc = cost + c
      next if dist[to] < nc

      q.push([to, nc])
    end
  end

  dist
end

dist = dijkstra(1, graph, n)
r_dist = dijkstra(1, r_graph, n)

result = 0
(1..n).each do |i|
  total_cost = dist[i] + r_dist[i]
  result = [result, aa[i-1]*(t-total_cost)].max
end
#p dist
#p graph

#p r_dist
#p r_graph

p result
