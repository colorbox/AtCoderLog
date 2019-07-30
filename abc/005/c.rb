t = gets.strip.to_i
n = gets.strip.to_i
a = gets.strip.split.map(&:to_i)
m = gets.strip.to_i
b = gets.strip.split.map(&:to_i)

result = 0
a.each do |current_a|
  current_b = b.first
  if current_b <= current_a+t && current_b >= current_a
    result += 1
    b.shift
  end
  break if b.empty?
end

if result==m
  puts 'yes'
else
  puts 'no'
end
