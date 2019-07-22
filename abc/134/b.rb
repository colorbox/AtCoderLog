n, d = gets.strip.split.map(&:to_i)

result=(n.to_f/(d*2+1).to_f).ceil

p result.to_i
