
# require 'byebug'
# with one line array

n, w = gets.strip.split.map(&:to_i)
vws = readlines.map {|line| line.strip.split.map(&:to_i) }

dp = Array.new(w+1, 0)

n.times do |i|
  cv, cw = vws[i]

  (0..w).to_a.reverse.each do |after_w|

    if after_w < cw
    else
      # p [dp[after_w], dp[after_w - cw] + cv]
      dp[after_w] = [dp[after_w], dp[after_w - cw] + cv].max
      # p dp
    end
  end
end

# p dp
p dp.max
