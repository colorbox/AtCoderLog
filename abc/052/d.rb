n, a, b = gets.strip.split.map(&:to_i)
x = gets.strip.split.map(&:to_i)

costs = (n-1).times.map {|i|
  current = (x[i+1] - x[i])*a
  current > b ? b : current
}

p costs.inject(:+)
