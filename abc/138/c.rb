n = gets.strip.to_i
v = gets.strip.split.map(&:to_i).sort

(n-1).times do |i|
  current = v.shift
  target = v.shift
  current = (current + target)/2.to_f
  v.unshift(current)
end
p v.first
