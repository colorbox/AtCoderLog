n, m = gets.strip.split.map(&:to_i)
abc = readlines.map {|line| line.strip.split.map(&:to_i) }

graph = Array.new(n+1) { [10**12]*(n+1) }
abc.each do |a, b, c|
  graph[a][b] = c
  graph[b][a] = c
end

(1..n).each do |i|
  graph[i][i]=0
end

vias = Array.new(n+1) { [false]*(n+1) }
abc.each do |a, b, c|
  vias[a][b] = vias[b][a] = true
end


minimum_edges = Array.new(n+1) { []*(n+1) }
(1..n).each do |via|
  (1..n).each do |from|
    (1..n).each do |to|
      if graph[from][to] > graph[from][via] + graph[via][to]
        graph[from][to] = graph[from][via] + graph[via][to]
        vias[from][to] = false
      end
    end
  end
end

p abc.count {|a, b, _| !vias[a][b] }
