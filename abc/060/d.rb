n, w = gets.strip.split.map(&:to_i)
wv = readlines.map {|line| line.strip.split.map(&:to_i) }
w1 = wv[0][0]

wv = wv.map {|ww, vv|  [ww-w1, vv]}
#p wv

width = n*3+3+1
dp = Array.new(n+1) { [-1]*(width) }
dp[0][0]=0

wv.each do |cw, cv|
  (0...n).to_a.reverse.each do |i|
    (width).times do |j|
      dp[i+1][j+cw] = dp[i][j] + cv if dp[i][j] != -1 && dp[i+1][j+cw] < dp[i][j] + cv
    end
  end
end

#dp.each {|l| p l }

result = [0,0]
dp.each_with_index do |line, i|
  line.each_with_index do|v, j|
    result = [j+w1*i, v] if v > result.last && j+w1*i <= w
  end
end

p result.last
