n = gets.strip.to_i
a = gets.strip.split.map(&:to_i)

result = n-a.group_by(&:itself).to_a.map {|e| e.last.length-1 }.inject(0, :+)
result-=1 if result.even?
p result
