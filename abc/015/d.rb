# from https://atcoder.jp/contests/abc015/submissions/2478266

w = gets.strip.to_i
n, k = gets.strip.split.map(&:to_i)
ab = readlines.map {|line| line.strip.split.map(&:to_i) }

dp = Array.new(k+1) { {} }
dp[0][0]=0

ab.each do |cw, ci|
  (k-1).downto(0) do |ck|
    dp[ck].each do |bw, v|
      if bw + cw <= w
        updated_importance = v + ci
        current_importance = dp[ck+1][bw + cw]
        dp[ck+1][bw + cw] = updated_importance if !current_importance || current_importance < updated_importance
      end
    end
  end
end

# p dp

p dp.map{|e|e.values}.flatten.max
