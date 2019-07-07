n, a = gets.strip.split(' ').map(&:to_i)
x = gets.strip.split(' ').map(&:to_i).map {|x| x-a }.sort

dp=Hash.new(0)
dp[0]=1

n.times do |num|
  copy_dp = dp.dup
  copy_dp.each do |k, v|
    dp[k + x[num]] += v
  end
end

#p x
p dp[0]-1
