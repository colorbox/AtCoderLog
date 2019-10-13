n, m = gets.strip.split.map(&:to_i)
abcn = n.times.map { gets.strip.split.map(&:to_i) }
xyz = m.times.map { gets.strip.split.map(&:to_i) }

dp = Array.new(101) { Array.new(101) { [0]*101 } }

abcn.each do |a, b, c, n|
  dp[a][b][c] = n if dp[a][b][c] < n
  # p [a,b,c,n, dp[a][b][c]]
end

c=0
101.times do |i|
  ii = [i-1, 0].max
  101.times do |j|
    jj=[j-1, 0].max
    101.times do |k|

      dp[i][j][k] = [ dp[i][j][k], dp[ ii ][j][k], dp[i][ jj ][k], dp[i][j][ k-1<0 ? 0 : k-1  ]].max
    end
  end
end

# p dp

xyz.each do |x, y, z|
  p dp[x][y][z]
end
