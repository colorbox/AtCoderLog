nums = gets.strip.split.map(&:to_i)

p nums.combination(3).map{|num|num.inject(:+)}.sort[-3]
