n=gets.strip.to_i
a = gets.strip.split.map(&:to_f)

m = (a.inject(:+)/n.to_f).round.to_i

result = a.inject(0) {|sum, current| sum + (m-current)**2 }
p result.to_i
