r, d, x_2000 = gets.strip.split.map(&:to_i)

xs = [x_2000]

(1..10).each do |n|
  current = r * xs.last - d
  xs.push(current)
  puts current
end
