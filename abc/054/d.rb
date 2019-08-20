n, ma, mb = gets.strip.split.map(&:to_i)
abc = readlines.map {|line| line.strip.split.map(&:to_i) }

limit = 40*10
medicine_limit = 40
INF = 10**12

dp = Array.new( medicine_limit+1 ) { Array.new( limit+1 ) { [INF]*(limit+1) } }
dp[0][0][0]=0

abc.each_with_index do |abc, abci|
  a, b, c = abc
#  dp[abci][a][b]=c if dp[abci][a][b]==INF
#  dp[abci][a][b] = [ c, dp[abci][a][b] ].min

  limit.times do |i|
    limit.times do |j|
      next if dp[abci][i][j]==INF

      dp[abci+1][i][j] = [ dp[abci+1][i][j], dp[abci][i][j] ].min
      dp[abci+1][i+a][j+b] = [ dp[abci+1][i+a][j+b], dp[abci][i][j]+c ].min

    end
  end
end

result = INF

limit.times do |i|
  limit.times do |j|
    ii = (i+1)
    jj= (j+1)
    if (ii*mb == jj*ma)
      result = [ dp[n][ii][jj], result ].min
    end
  end
end

if result == INF
  p -1
  exit
end

p result
