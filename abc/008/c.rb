n = gets.strip.to_i
c = readlines.map {|line| line.strip.to_i }

result = 0.0
n.times do |index|

  current_c = c[index]
  count = c.select {|t| (current_c%t).zero? }.length - 1

  current = count.odd? ? (0.5) : (count.to_f+2)/((count.to_f+1)*2)
#p [count, current, current_c]
  result += current

end

p result
