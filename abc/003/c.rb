n, k = gets.strip.split.map(&:to_i)
r = gets.strip.split.map(&:to_f).sort

result = 0.0
k.times do |index|
  result = (result + r[n-k+index])/2
end

p result
