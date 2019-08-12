n = gets.strip.to_i
a = gets.strip.split.map(&:to_i).sort

max_a = a.last

half_max_a = a.first

half_max = max_a/2.0
a.each do |current|
  half_max_a = current if (half_max - current).abs < (half_max - half_max_a).abs
end

puts [max_a, half_max_a].join(' ')
