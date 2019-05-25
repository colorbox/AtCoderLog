a, b = gets.strip.split.map(&:to_i)

result =
  if a >= 13
    b
  elsif a >= 6
    b/2
  else
    0
  end

puts result
