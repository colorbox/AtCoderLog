n,m = gets.strip.split.map(&:to_i)

if n > m/2
  p (m/2).ceil
  exit
end

p n + ((m-2*n)/4).ceil
