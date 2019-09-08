h, w, d = gets.strip.split.map(&:to_i)
a = h.times.map { gets.strip.split.map(&:to_i) }
q = gets.strip.to_i
lr = readlines.map {|line| line.strip.split.map(&:to_i) }

route = Array.new(h*w+1)

h.times do |y|
  w.times do |x|
    route[a[y][x]] = [y, x]
  end
end

cum_costs = Array.new(h*w+1, 0)
(h*w).times do |i|
  c = i+1
  from = route[c]
  to = route[c+d]
  break if to.nil?
  cum_costs[c+d] = cum_costs[c] + from.zip(to).map {|f,t| (f-t).abs }.inject(:+)
end

lr.each do |l, r|
  p cum_costs[r] - cum_costs[l]
end
