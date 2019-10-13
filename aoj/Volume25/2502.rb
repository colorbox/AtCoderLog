n = gets.strip.to_i
slp = n.times.map { gets.strip.split.map(&:to_i) }

m = gets.strip.to_i
ww = m.times.map { gets.strip.to_i }

lp = slp.map {|s,l,p| (l-s+1).times.map {|length| [s+length, p] } }.inject(:+).uniq

max_w = ww.max
dp = [0]*(max_w+1)

lp.each_with_index do|(len, point), i|
  (max_w+1).times do |j|
    if j >= len
      dp[j] = [ dp[j], dp[j-len] + point ].max
    end
    # p dp
    # require'byebug'; byebug
  end
end

results = ww.map {|w| dp[w] }

# p results

if results.any?{|w| w.zero? }
  p -1; exit
end

# p dp

results.each do |r|
  p r
end
