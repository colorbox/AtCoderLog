n = gets.strip.to_i
ab = readlines.map {|line| line.strip.split.map(&:to_i) }

max = ab.map(&:last).sort.last

cum = [0]*(max+2)

ab.each do |tmp|
  left = tmp.first
  right = tmp.last
  cum[left] += 1
  cum[right+1] -= 1
end

(1..max).each do |current|
  cum[current] = cum[current] + cum[current-1]
end

#cum.pop
#p cum
p cum.max
