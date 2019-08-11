h, w = gets.split.map(&:to_i)
a = readlines.map {|line| line.strip.split.map(&:to_i) }

odd_coins = 0

one_path = []
h.times do |i|
  tmp = []
  w.times do |j|
    tmp << [i, j]
  end
  tmp = tmp.reverse if i.odd?
  one_path += tmp
end

results = []
tmp_result = []
from=nil
one_path.each  do |current|
  coin = a[current[0]][current[1]]

  unless from.nil?
    results.push( [from, current] )
    from = current
  end

  if coin.odd?
    if from
      from = nil
    else
      from = current
    end
  end

end

#p results
p results.length

results.each do |r|
  puts r.flatten.map {|n| n+1 }.join(' ')
end
