require 'prime'
require 'set'

a, b = gets.strip.split.map(&:to_i)

pd_b = Set.new(Prime.prime_division(b).map(&:first))
pd_a = Set.new(Prime.prime_division(a).map(&:first))

# p pd_a
# p pd_b

p 1+ (pd_a & pd_b).size
