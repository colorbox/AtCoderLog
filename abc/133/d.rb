n = gets.strip.to_i
a = gets.strip.split(' ').map(&:to_i)

rain = a.inject(:+)

even_index_sum = a.map.with_index {|tmp, index| (index+1).even? ? tmp : 0 }.inject(:+)
first = rain - 2*even_index_sum

results=[]
results.push(first)

(1..n-1).to_a.each do |num|
  results.push(a[num-1]*2-results[num-1])
end


puts results.join(' ')
