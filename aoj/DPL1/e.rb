s1=gets.strip.split('')
s2=gets.strip.split('')

dp = Array.new(s1.length+1) { [0]*(s2.length+1) }

(s1.length+1).times {|i| dp[i][0]=i }
(s2.length+1).times {|i| dp[0][i]=i }

s1.each_with_index do |c1, i|
  s2.each_with_index do |c2, j|
    c = c1==c2 ? 0 : 1
    dp[i+1][j+1] = [
      dp[i+1][j]+1,
      dp[i][j+1]+1,
      dp[i][j]+c
    ].min
  end
end

# dp.each{|l|p l}

p dp.last.last
