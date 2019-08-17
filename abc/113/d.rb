h, w, k = gets.strip.split.map(&:to_i)
MOD = 10**9+7

dp = Array.new(h+1) { Array.new(w, 0) }
dp[0][0]=1

h.times do |ch|
  (0 ... 1 << (w-1)).each do |bit|
    invalid_amida = ("%0#{w}b" % bit).split('').map(&:to_i).each_cons(2).map {|l, r| l==1 && r==1 }.any?
    next if invalid_amida

    w.times do |cw|
      if cw != w-1 && bit[cw]==1
        next_target = cw+1
      elsif cw != 0 && bit[cw-1]==1
        next_target = cw-1
      else
        next_target = cw
      end
      dp[ch+1][next_target] = (dp[ch+1][next_target] + dp[ch][cw]) % MOD
    end
  end
end

#p dp
p dp[h][k-1]
