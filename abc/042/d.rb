h, w, a, b = gets.strip.split.map(&:to_i)
MOD = 10**9+7

def power(x, n)
  return 1 if n.zero?

  if n.even?
    return power(x*x, n/2) % MOD
  else
    return x*power(x, n/2)**2 % MOD
  end
end

$fac = []
$fac[0] = $fac[1] = 1
2.upto(h+w) do |num|
  $fac[num] = num * $fac[num-1] % MOD
end

$ifac = []
$ifac[0] = $ifac[1] = 1
$ifac[h+w-2] = power($fac[h+w-2], (MOD-2)) % MOD
(h+w-3).downto(2) do |num|
  $ifac[num] = $ifac[num+1] * (num+1) % MOD
end

def comb(n,k)
  return 0 if n<k || n<0 || k<0
  $fac[n] * ($ifac[n-k] * $ifac[k] % MOD) % MOD
end

sum = 0
(b+1).upto(w) do |num|
  c1 = comb(h-a-1+num-1, num-1)
  c2 = comb(a-1+w-num+1-1, a-1)

  sum += c1*c2 % MOD
end

p sum%MOD

#p $fac
#p $ifac
