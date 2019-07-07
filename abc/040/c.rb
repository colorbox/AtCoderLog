n = gets.strip.to_i
a = gets.strip.split(' ').map(&:to_i)

dp=[0, (a[0]-a[1]).abs]

if n==2
  p dp.last
  exit
end

(2..n-1).to_a.each do |index|
  one_before = dp[index-1] + (a[index] - a[index-1]).abs
  two_before = dp[index-2] + (a[index] - a[index-2]).abs
  dp[index] = [one_before, two_before].min
end

p dp.last
