require 'prime'

q = gets.strip.to_i
lr = readlines.map {|line| line.strip.split.map(&:to_i) }

max_r = lr.map(&:last).sort.last

cum = Array.new(max_r+1, 0)

1.step(max_r, 2) do |num|
  cum[num]+=1 if num.prime? && ((num+1)/2).prime?
end

(cum.length-1).times do |i|
  cum[i+1] = cum[i] + cum[i+1]
end

lr.each do |cl, cr|
  p cum[cr] - cum[cl-1]
end
