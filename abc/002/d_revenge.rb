n, m = gets.strip.split.map(&:to_i)
xy = readlines.map {|line| line.strip.split.map(&:to_i) }

graph=Array.new(n+1) { [] }
xy.each do |x, y|
  graph[x] << y
  graph[y] << x
end

result = 0
(2**(n)).times do |i|
  c_s = i.to_s(2).split('').map(&:to_i).reverse.map.with_index {|e, i| [e, i] }.select {|e, i| !e.zero? }.map {|e, i| i+1 }
  if c_s.all? {|e| (c_s-[e]).all? {|ce| graph[e].include?(ce) } }
#    p [i, c_s]
    tmp = c_s.length
    result = tmp if tmp > result

  end
end

p result
