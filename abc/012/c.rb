n = gets.strip.to_i

sum = 0
9.times do |i|
  9.times do |j|
    sum += (i+1)*(j+1)
  end
end

diff = sum - n

results = []
9.times do |i|
  9.times do |j|
    current = (i+1)*(j+1)
    results.push([i+1, j+1]) if current==diff
  end
end

results.sort.each do |result|
  puts "#{result.first} x #{result.last}"
end
