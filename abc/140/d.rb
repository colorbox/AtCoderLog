n = gets.strip.to_i
b = gets.strip.split.map(&:to_i)

result = 0
b.each_cons(2) do |bs|
  result += bs.min
end
result += b.first+b.last

p result
