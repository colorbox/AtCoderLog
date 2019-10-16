#copied from https://atcoder.jp/contests/maximum-cup-2018/submissions/2851272

n, m, l, x = gets.strip.split.map(&:to_i)
aa = gets.strip.split.map(&:to_i)

dp = Array.new(m, x+1)
dp[0]=1

aa.each do |a|
  ndp = dp.dup
  m.times do |j|
    d2 = dp[ (j-a)%m ] + (j+a)/m
    h = {'a' => a, 'j' => j, 'ndp[j] > d2' => (ndp[j] > d2), "ndp[j]" => ndp[j], 'd2 = dp[ (j-a)%m ] + (a+j)/m ' => (dp[ (j-a)%m ] + (a+j)/m), 'dp[ (j-a)%m ]' => dp[ (j-a)%m ], '(a+j)/m' => (a+j)/m }
    # h = {'a' => a, 'j' => j, 'ndp[j] > d2' => (ndp[j] > d2), "ndp[j]" => ndp[j], 'd2 = dp[ (j+a)%m ] + (a+j)/m ' => (dp[ (j+a)%m ] + (a+j)/m), 'dp[ (j+a)%m ]' => dp[ (j+a)%m ], '(a+j)/m' => (a+j)/m }
    p h
    ndp[j] = d2 if ndp[j] > d2
    p ndp
    require 'byebug';byebug
  end
  dp=ndp
end

if dp[l] <= x
  puts 'Yes'
else
  puts 'No'
end
