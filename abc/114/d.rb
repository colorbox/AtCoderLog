require 'prime'

n = gets.strip.to_i

divided = n.downto(1).inject({}) {|memo, num|
  num.prime_division.each {|div, count|
    if memo[div].nil?
      memo[div]=count
    else
      memo[div]+=count
    end
  }
  memo
}.to_a

factor_counts = divided.map(&:last)

counts_4_arr = factor_counts.select {|f| f >= 4 }.to_a
counts_4 = factor_counts.select {|f| f >= 4 }.to_a.length
counts_2 = factor_counts.select {|f| f >= 2 }.to_a.length
counts_14 = factor_counts.select {|f| f >= 14 }.to_a.length
counts_24 = factor_counts.select {|f| f >= 24 }.to_a.length
counts_74 = factor_counts.select {|f| f >= 74 }.to_a.length

with_4_4_2 =  counts_4_arr.combination(2).to_a.length * (counts_2-2)
with_24_2 =  counts_24 * (counts_2-1)
with_14_4 = counts_14 * (counts_4-1)
with_74_0 = counts_74

p with_4_4_2 + with_24_2 + with_14_4 + with_74_0
