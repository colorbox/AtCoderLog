n, x = gets.strip.split.map(&:to_i)
a = gets.strip.split.map(&:to_i)

result=0;
(n-1).times do|index|
  superior = [(a[index] + a[index+1]) - x, 0].max
  result +=superior
  if a[index+1] >= superior
    a[index+1] = a[index+1] - superior
  else
    rest = superior - a[index+1]
    a[index+1] = 0
    a[index] = a[index]-rest
  end
end

p result
