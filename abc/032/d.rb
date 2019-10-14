n, w = gets.strip.split.map(&:to_i)
vw = readlines.map {|line| line.strip.split.map(&:to_i) }

max_v = vw.map(&:first).inject(:+)

INF=10**14
# INF=10**2
dp = Array.new(n+1) { [0]*(max_v+1) }
dp[0] = [INF]*(n*max_v+1)
dp[0][0]=0

vw.each_with_index do |(cv, cw),i|
  (max_v+1).times do |j|
    if j < cv
      dp[i+1][j] = dp[i][j]
    else
      dp[i+1][j] = [ dp[i][j-cv]+cw, dp[i][j] ].min
    end
  end
end

# p dp.last.map.with_index {|e,i| [e, i] }

result = 0
dp.last.each_with_index do |e, i|
  # if e <= w && i > result
  #   p [e, i]
  # end
  result = i if e <= w && i > result
end
# require'byebug';byebug

p result

