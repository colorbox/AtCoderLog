n = gets.strip.to_i
b = readlines.map.with_index {|line, index| [line.to_i, index+2] }

def salary_calc(no, bosses)
  unders = bosses.select {|boss| boss.first==no }
  return 1 if unders.count.zero?
  unders.map {|number| salary_calc(number.last, bosses) }.minmax.inject(:+)+1
end

p salary_calc(1, b)
