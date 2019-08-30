n = gets.strip.to_i

MOD = 10**9+7

dp = {'' => 1}

n.times do
  next_hash = Hash.new(0)

  dp.each do |k, v|
    'AGCT'.chars.each do |c|
      # s = (k+c)[1..-1]
      s = (k+c)
      s = s[1..-1] if s.length == 5
      next if s.match(/AGC|GAC|ACG|AG.C|A.GC/)
      next_hash[s] += v
      next_hash[s] %= MOD
    end
  end
  # p dp
  # p '-'

  dp = next_hash
end

# p dp
p dp.values.inject(:+) % MOD
