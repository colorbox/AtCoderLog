
# 気になる https://twitter.com/color_box/status/1183299979328118785

n = gets.strip.to_i
slp = n.times.map { gets.strip.split.map(&:to_i) }

m = gets.strip.to_i
ww = m.times.map { gets.strip.to_i }

lp = slp.map {|s,l,p| (l-s+1).times.map {|length| [s+length, p] } }.inject(:+).uniq

max_w = ww.max
dp = Array.new(lp.length+1) { [0]*(max_w+1) }

lp.each_with_index do|(len, point), i|
  (max_w+1).times do |j|
    if j >= len
      dp[i+1][j] = [ dp[i][j], dp[i+1][j-len] + point, dp[i][j-len] + point ].max
    else
      dp[i+1][j] = dp[i][j]
    end
    # dp.each {|l|p l}
    # require'byebug'; byebug
  end
end

results = ww.map {|w| dp.last[w] }

if results.any?{|w| w.zero? }
  p -1; exit
end

# p dp.last

results.each do |r|
  p r
end
