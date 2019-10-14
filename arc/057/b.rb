#from https://atcoder.jp/contests/arc057/submissions/2548436

n, k = gets.strip.split.map(&:to_i)
aa = readlines.map {|l| l.strip.to_i }

asum = aa.dup
(n-1).times do |i|
  asum[i+1] += asum[i]
end

if k.zero?
  p 0; exit
end

if k == asum.last
  p 1; exit
end

big = k+1
dp = Array.new(n) { Array.new(n+1, big) }
dp[0][0]=0
dp[0][1]=1
(1...n).each do |i|
  (1..(i+1)).each do |j|
    dp[i][j] = dp[i-1][j]
    d2 = dp[i-1][j-1] * (asum[i]/asum[i-1])+1
    if d2 <= k && d2 - dp[i-1][j-1] <= aa[i] && d2 < dp[i][j]
      dp[i][j] = d2
    end
    # dp.each {|l|p l}
    # require 'byebug'; byebug
  end
end

# p"-------"
# dp.each {|l|p l}

p (0..n).select {|i| dp[n-1][i] < big }.max
