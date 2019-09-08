require 'prime'

n, m = gets.strip.split.map(&:to_i)
MOD = 10**9+7

dims = m.prime_division.map(&:last)

def power(n, k)
  return 1 if k.zero?
  if k.even?
    power(n, k/2)**2 %MOD
  else
    n*power(n, (k-1)/2)**2 %MOD
  end
end

maximum = n+(dims.max || 0)
@factor = [1,1]
(2..maximum).each do |i|
  @factor[i] = @factor[i-1] * i
  @factor[i] %= MOD
end

@ifactor = [1,1]
@ifactor[maximum] = power(@factor[maximum], MOD-2)
(maximum-1).downto(2).each do |i|
  @ifactor[i] = @ifactor[i+1]*(i+1)
  @ifactor[i] %= MOD
end

result=1
dims.each do |d|
  # (n+d)C(d)
  comb = (@factor[n+d-1]*(@ifactor[n-1]*@ifactor[d]%MOD)%MOD)
  result *= comb
  result %= MOD
  #p [n, d, comb, @factor[n+d-1], @ifactor[n-1], @ifactor[d]]
end

p result
