n, w = gets.strip.split.map(&:to_i)
vw = readlines.map {|l| l.strip.split.map(&:to_i) }

dp = Array.new(n+1) { [0]*(w+1) }

(n).times do |i|
  (w+1).times do |j|
    cv, cw = vw[i]
    if j < cw
      dp[i+1][j] = dp[i][j]
    else
      dp[i+1][j] = [dp[i][j], dp[i+1][j-cw]+cv].max
    end
  end
end

# dp.each {|l|p l}

p dp.last.last
