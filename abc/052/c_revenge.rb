require 'prime'
n = gets.strip.to_i

MOD = 10**9+7

log = {}
(1..n).each do|num|
  divs = Prime.prime_division(num)
  divs.each do|number, factors|
    log[number] ||= 1
    log[number] += factors
  end
end

result=1
log.each do|num, count|
  result = (result * count)%MOD
end

p result
