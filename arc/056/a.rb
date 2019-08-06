a, b, k, l = gets.strip.split.map(&:to_i)

p [a*k, (k/l)*b + (k%l)*a, (k/l)*b+b].min
