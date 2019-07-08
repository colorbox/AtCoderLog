n = gets.strip.to_i
a = readlines.map {|line| line.strip.to_i }

ranks = a.uniq.sort.map.with_index {|x, index| [x,index] }.to_h

results = a.map {|num|
  ranks[num]
}

results.each do |num|
  p num
end
