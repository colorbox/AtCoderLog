n, m = gets.strip.split.map(&:to_i)
lrd = readlines.map {|line| line.split.map(&:to_i) }

graph = Array.new(n+1) { [] }
lrd.each do |l, r, d|
  graph[l] << [r, d]
  graph[r] << [l, -d]
end

check = Array.new(n+1)

def bfs(start, check, graph)
  check[start]=0
  queue = [start]

  until queue.empty?
    current_start = queue.shift
    graph[current_start].each do |goal, cost|
      if check[goal].nil?
        check[goal] = check[current_start] + cost
        queue << goal
      else
        return false if check[goal] != check[current_start] + cost
      end
    end
  end

  return true
end

if (1..n).all? {|number| check[number] || bfs(number, check, graph) }
  puts 'Yes'
else
  puts 'No'
end
