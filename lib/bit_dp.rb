# from https://atcoder.jp/contests/abc041/submissions/4541820

require 'byebug'

N, M=gets.chomp.split.map(&:to_i)

bb = Array.new(N,0)
p bb
M.times do
  x,y=gets.chomp.split.map(&:to_i)
  bb[x-1] |= 1<<(y-1)
  p bb
end
p"###"
dp = Array.new(1<<N,0)
dp[0]=1

0.upto((1<<N) - 1) do |ii|
  p ii
  0.upto(N-1) do |j|
    p j
    t = 1<<j
    p [(ii & t), (bb[j] & ii), ((ii & t) == 0 and (bb[j] & ii) == 0)]
    byebug
    if (ii & t) == 0 and (bb[j] & ii) == 0
      dp[ii|t] += dp[ii]
    end
  end
  p"---"
end

p dp

puts dp[-1]
