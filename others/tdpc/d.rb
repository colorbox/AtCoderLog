require 'byebug'

require 'prime'

# n, d=gets.strip.split.map(&:to_i)
n, d=[2,6]

if Prime.prime_division(d).map(&:first).reject{|e| [2,3,5].include?(e)}.length>0
  p 0; exit
end

h=Prime.prime_division(d).to_h
nums = [ h[2]||0, h[3]||0, h[5]||0 ]

dp = Hash.new(0)
dp[1]=dp[2]=dp[3]=dp[4]=dp[5]=dp[6]=1

(n-1).times do
  tmp=dp.dup
  dp.each do |k, cnt|
    (1..6).each do |cc|
      p tmp
      byebug
      tmp[k*cc] += cnt
    end
  end
  dp=tmp
  p dp
end

result=0
td=d
while td <= 6**n
  p [result,dp[td], td]
  result += dp[td]
  td+=d
end

p result
