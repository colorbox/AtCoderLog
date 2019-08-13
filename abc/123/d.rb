x, y, z, k = gets.strip.split.map(&:to_i)
a = gets.strip.split.map(&:to_i).sort
b = gets.strip.split.map(&:to_i).sort
c = gets.strip.split.map(&:to_i).sort


ab = a.map {|c_a| b.map {|c_b| c_b + c_a} }.flatten.sort.last(k)
abc = ab.map {|c_ab| c.map {|c_c| c_c + c_ab } }.flatten.sort.last(k).reverse
abc.each do |c_abc|
  p c_abc
end
