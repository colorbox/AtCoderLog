n, m = gets.strip.split.map(&:to_i)
uv = readlines.map {|line| line.strip.split.map(&:to_i) }

graph = Array.new(n+1) { [] }
uv.each do |u, v|
  graph[u] << v
  graph[v] << u
end

result = 0
visited = [false]*(n+1)
(1..n).each do |s|
  next if visited[s]
  visited[s] = true
  stack = [[s,0]]
  is_tree = true
  until stack.empty?
    c, last = stack.pop
    (graph[c] - [last]).each do |nex|
      unless visited[nex]
        stack.push([nex, c])
        visited[nex] = true
      else
        is_tree = false
      end
    end
  end

  result += 1 if is_tree
end

p result
