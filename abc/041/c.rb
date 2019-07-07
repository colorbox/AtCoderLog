n = gets.strip.to_i
a = gets.strip.split(' ').map.with_index {|x, index| [x.to_i, index+1] }.sort_by {|x| -1 * x.first }

a.each do |student|
  p student.last
end
