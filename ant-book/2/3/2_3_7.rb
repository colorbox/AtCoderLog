# 分割数

require 'byebug'

# n, m = gets.strip.split.map(&:to_i)
n,m=[4,3]

dp = Array.new(m+1) { [0]*(n+1) }
dp[0][0]=1

(1..m).each do |i|
  (0..n).each do |j|
    if (j-i >= 0)
      p [i, j]
      # byebug
      dp[i][j] = (dp[i-1][j]+dp[i][j-i])
    else
      dp[i][j]=dp[i-1][j]
    end
  end
end
dp.each {|l|p l}
p dp[m][n]
