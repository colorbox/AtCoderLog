n=gets.strip.to_i
problems = n.times.map { [gets.strip.split(''), gets.strip.split('')] }

def solve(l_s, r_s)
  dp=Array.new(l_s.length+1) { [0]*(r_s.length+1) }

  l_s.each_with_index do |lc, i|
    r_s.each_with_index do |rc, j|
      if lc==rc
        dp[i+1][j+1] = dp[i][j]+1
      else
        dp[i+1][j+1] = [dp[i+1][j], dp[i][j+1]].max
      end
    end
  end

  dp[l_s.length][r_s.length]
end

problems.each do |lstr, rstr|
  p solve(lstr, rstr)
end
