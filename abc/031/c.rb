n  =gets.strip.to_i
a = gets.strip.split.map(&:to_i)

def calc_score(nums)
  [
    nums.select.with_index {|x, i| (i+1).odd? }.inject(:+),
    nums.select.with_index {|x, i| (i+1).even? }.inject(:+)
  ]
end

result = -Float::INFINITY

n.times do |i|
  current_most = -Float::INFINITY
  t_score = 0

  n.times do |j|
    next if i==j
    s, t = [i, j].minmax

    os, es = calc_score(a[s..t])
    if current_most < es
      current_most = es
      t_score = os
    end
  end

  result = [result, t_score].max
end

p result
