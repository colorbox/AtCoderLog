# from https://atcoder.jp/contests/arc057/submissions/2408252

N, K = gets.split.map(&:to_i)
a = Array.new(N) { gets.to_i }

dp = Array.new(N+1) { Array.new(N+1, K+1) }
dp[0][0] = 0
dp[1][0] = 0
dp[1][1] = 1

sum = a[0]
(1..N-1).each do |i|
  (0..i).each do |j|
    dp[i+1][j]   = dp[i][j]   if dp[i+1][j] > dp[i][j]
    dp[i+1][j+1] = dp[i][j+1]

    dpp = dp[i][j] * a[i] / sum + 1
    dp[i+1][j+1] = dp[i][j] + dpp if dpp <= a[i]
  end
  sum += a[i]
end

if sum == 0
  puts 0; exit;
elsif sum == K
  puts 1; exit;
end

dp.each {|l|p l}

puts dp[N].map.with_index.select { |k, _| k <= K }[-1][-1]
