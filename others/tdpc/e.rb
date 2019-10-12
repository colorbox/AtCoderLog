require 'byebug'

D = gets.to_i
N = gets.chomp.split("").map(&:to_i)
n = N.size-1
ans = 0
dp = Array.new(n).map{Array.new(D,0)}
(0..9).each do |i|
  dp[0][i%D] += 1
end

p dp
byebug

(n-1).times do |ii|
  dp[ii].each_with_index do |vv,j|
    10.times do |k|
      ll = (j+k)%D
      dp[ii+1][ll] += vv
      p dp
      byebug
    end
  end
  for j in 0..D-1
    dp[ii+1][j] %= 10**9+7
  end
  p dp
  byebug
end

p dp

stack = 0
N.reverse!
n.downto(1) do |i|
  for j in 0..N[i]-1
    ans += dp[i-1][(D-stack-j)%D]
  end
  ans %= 10**9+7
  stack += N[i]
end

p stack

stack += N[0]
for i in 0..N[0]
  if (stack+i)%D == 0
    ans += 1
  end
end


p (ans-1)%(10**9+7)
