INF = Float::INFINITY
MOD = 10**9+7
N = gets.to_i
a, b = gets.split.map(&:to_i).map {|e| e-1 }

M = gets.to_i

path = Hash.new {|h, k| h[k]=[] }.tap {|h|
  M.times do
    x, y = gets.split.map(&:to_i).map {|e| e-1 }.minmax
    h[x] << y
    h[y] << x
  end
}

dist = [INF]*(N)
count = [0]*(N)

dist[a] = 0
count[a]=1

queue=[a]

loop do
#p [dist, count]
  x = queue.shift
  break if x==b
  path[x].each do |y|
    if dist[y]==INF
      dist[y] = dist[x]+1
      count[y] += count[x]
      queue << y
    elsif dist[y] == dist[x]+1
      count[y] += count[x]
    end
  end
end

#p path

puts count[b]%MOD
