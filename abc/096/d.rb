require 'prime'

def valid(nums)
  nums.combination(5).all? {|nums| nums.inject(:+).prime_division.length!=1 }
end

n = gets.strip.to_i

correct_primes = (2..55555).to_a.select(&:prime?).select {|e| e%5==1 }

puts correct_primes[0..n-1].join(' ')
