n, k = gets.strip.split(' ').map(&:to_i)
a = gets.strip.split(' ').map(&:to_i)

if n==1
  p a.first
  exit
end

cum_a = [a.first]
(1..n-1).to_a.each do |index|
  cum_a[index] = cum_a[index-1] + a[index]
end

if (n-k).zero?
  p cum_a[k-1]
  exit
end

results = [cum_a[k-1]]
(1..n-k).to_a.each do |index|
  results[index] = cum_a[k-1+index] - cum_a[index-1]
end

puts results.inject(:+)
