#copied from https://atcoder.jp/contests/maximum-cup-2018/submissions/2408375

n, m, l, x = gets.strip.split.map(&:to_i)
aa = gets.strip.split.map(&:to_i)

dp = Array.new(m, x+1)
dp[0]=1

aa.each do |a|
  ndp = dp.dup
  m.times do |j|
    ndp[(j+a)%m] = [ dp[(j+a)%m], dp[j]+(j+a)/m ].min
  end
  dp=ndp
end

if dp[l] <= x
  puts 'Yes'
else
  puts 'No'
end

