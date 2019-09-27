require 'byebug'

D,G = gets.split.map(&:to_i)
N = 1001
dp = Array.new(N,0)

p [D,G]

pc = D.times.map { gets.split.map(&:to_i) }

1.upto(D) do |i|
  pi,c = pc[i-1]
  (N-1).downto(0) do |j|
    max = dp[j]
    pi.times do |k|
      if (j-k >= 0) && (max < dp[j-k] + i*k*100)
        max = dp[j-k] + i*k*100
      end
    end
    if (j-pi >= 0) && (max < dp[j-pi] + i*pi*100 + c)
      max = dp[j-pi] + i*pi*100 + c
    end
    dp[j] = max
  end
  # byebug
end
p dp[0..70]
N.times do |i|
  if dp[i] >= G
    p i
    break
  end
end
