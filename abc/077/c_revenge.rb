n = gets.strip.to_i
a = gets.strip.split.map(&:to_i).sort.reverse
b = gets.strip.split.map(&:to_i).sort
c = gets.strip.split.map(&:to_i).sort

#p a
#p b
#p c

result = 0
b.each do |current_b|
  a_count = a.length - (a.bsearch_index {|c_a| c_a < current_b } || a.length)
  c_count = c.length - (c.bsearch_index {|c_c| c_c > current_b } || b.length)
  result += a_count*c_count
end

p result
