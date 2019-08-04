n = gets.strip.to_i
h = gets.strip.split.map(&:to_i)

min=0
(n-1).times do |index|

#p [min, h[index], h[index+1]]

  min = h[index+1]-1 if h[index+1] > min
  if h[index+1] < min
    puts 'No'
    exit
  end

end

puts 'Yes'
