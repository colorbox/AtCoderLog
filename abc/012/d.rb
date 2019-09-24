n, m = gets.strip.split.map(&:to_i)
abt = readlines.map {|line| line.strip.split.map(&:to_i) }

INF = 10**10
graph = Array.new(n+1) { Array.new(n+1, INF) }
abt.each do |a, b, t|
  graph[a][b] = graph[b][a] = t
end
(n+1).times do |i|
  graph[i][i]=0
end

(1..n).each do |via|
  (1..n).each do |from|
    from_via = graph[from][via]
    (1..n).each do |to|
      from_to = from_via + graph[via][to]
      next if graph[from][to] < from_to

      graph[from][to] = graph[to][from] = from_to
    end
  end
end

#graph.each {|l|p l}

p graph.map {|e| e[1..-1].max }[1..-1].min
