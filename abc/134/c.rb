n = gets.strip.to_i
a = readlines.map {|line| line.strip.to_i }

max = a.sort.last

second_max = (a - [max]).sort.last
second_max = max if a.group_by {|e|e}[max].length>1

a.each do |e|
  if e==max
    p second_max
  else
    p max
  end
end
