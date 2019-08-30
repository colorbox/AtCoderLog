x, y = gets.strip.split.map(&:to_i)

if (x-y).abs <= 1
  puts 'Brown'
else
  puts 'Alice'
end
