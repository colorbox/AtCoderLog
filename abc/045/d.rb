h, w, n = gets.strip.split.map(&:to_i)
ab = readlines.map {|line| line.strip.split.map(&:to_i) }

B = 10**9+7
blacks = Hash.new(false)
ab.each do |a, b|
  k = a*B+b
  blacks[ k ]=true
end

count_array = [0]*10
square = Hash.new(0)
ab.each do |a, b|
  [a-2, a-1, a].each do |ca|
    next if ca<1 || ca > h-2
    [b-2, b-1, b].each do |cb|
      next if cb < 1 || cb > w-2

      k = ca*B + cb
      square[ k ] += 1
    end
  end
end

counters = square.values.flatten
ans = (1..9).map {|num| counters.count(num) }

all_count = (h-2)*(w-2)
ans.unshift(all_count - ans.inject(:+))
puts ans
