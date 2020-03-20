# require 'byebug'

n, w = gets.strip.split.map(&:to_i)
vws = readlines.map {|line| line.strip.split.map(&:to_i) }

dp = Array.new(n+1) { [0]*(w+1) }
dp[0][0]=0

n.times do |i|
  cv, cw = vws[i]

  (0..w).each do |after_w|

    # dp.each {|l|p l}
    # p "---"
    # byebug
    if after_w < cw
      dp[i+1][after_w] = dp[i][after_w]
    else
      dp[i+1][after_w] = [dp[i][after_w], dp[i][after_w - cw] + cv].max
    end
  end
end

# dp.each {|l|p l}

p dp.map(&:max).max
