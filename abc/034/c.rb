w, h = gets.strip.split(' ').map {|x| x.to_i }

mod = 10**9+7

factor = [1]*(h+w)
inv = [1]*(h+w)
finv = [1]*(h+w)

(2..(h+w)).each do |i|
  factor[i]=(factor[i-1] * i) % mod
  inv[i] = mod - (inv[mod%i]*(mod / i))%mod
  finv[i] = (finv[i-1] * inv[i])%mod
end

bigger = [w, h].max-1
smaller = [w, h].min-1

result = factor[bigger+smaller] * (finv[smaller] * finv[bigger] % mod)  % mod

p result
