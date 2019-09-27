n = gets.strip.to_i
tt = readlines.map {|line| line.strip.to_i }

result = tt.inject(:+)
(n**2).times do |state|

  tmp = tt.map.with_index {|t, ii| [t, ii] }.partition {|t, ii| state[ii].zero? }.map {|arr| arr.map(&:first).inject(:+) }.compact.max
  result = [result, tmp].min
end

p result
