h, w, d = gets.strip.split.map(&:to_i)
a = h.times.map { gets.strip.split.map(&:to_i) }
q = gets.strip.to_i
lr = readlines.map {|line| line.strip.split.map(&:to_i) }

point_hash = {}
a.each_with_index do |line, i|
  line.each_with_index do |point, j|
    point_hash[point] = [i, j]
  end
end

cum_d = [0]*(w*h+1)
(d+1..h*w).each do |i|
  s = point_hash[i-d]
  g = point_hash[i]
  cum_d[i] = cum_d[i-d] + (s[0] - g[0]).abs + (s[1] - g[1]).abs
end

lr.each do |l, r|
  p cum_d[r]-cum_d[l]
end
