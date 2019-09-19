n, m = gets.strip.split.map(&:to_i)
xx = gets.strip.split.map(&:to_i)
yy = gets.strip.split.map(&:to_i)
MOD = 10**9+7

x_len = 0
xx.each_with_index do |x, i|
  x_len += ((n-1-i)*x + -1*i*x)
end

y_len = 0
yy.each_with_index do |y, i|
  y_len += ((m-1-i)*y + -1*i*y)
end

p x_len*y_len%MOD
