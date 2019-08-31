require 'set'

n, k = gets.strip.split.map(&:to_i)
td = readlines.map {|line| line.strip.split.map(&:to_i) }.sort_by(&:last).reverse

already_max = Set.new
td = td.map do |t, d|
  unless already_max.include?(t)
    already_max.add(t)
    [1, d]
  else
    [0, d]
  end
end

all = td.sort.sort_by(&:last).reverse
#p all

selected = all.take(k)
unselected = all[k...n]

mobile = []
in_result = 0
selected.each do |t, d|
  if !t.zero?
    in_result+=1
  else
    mobile.push([t, d])
  end
end

current_score = selected.map(&:last).inject(:+)

result = current_score + in_result**2

if n==k
  p result
  exit
end

#p selected
unselected.each do |t, d|
  next if t.zero?

  swap_target = mobile.pop
  break if swap_target.nil?
  current_score -= swap_target.last
  current_score += d
  in_result+=1
  current_result = current_score + in_result**2

  if current_result > result
#    p [result, current_result, [current_score, in_result**2], t,d, swap_target]
    result = current_result
  end
end

p result
