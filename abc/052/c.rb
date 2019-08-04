require 'prime'
n = gets.strip.to_i

if n==1
  p 1
  exit
end

dividers = [0]*(n+1)
(1..n).each do |num|
  Prime.prime_division(num).each do |index, multi|
    dividers[index] += multi
  end
end

MOD = 10**9+7
result = dividers.select {|v| v>0 }.map {|e| e+1 }.inject {|m,v| (m*v)%MOD }
p result
