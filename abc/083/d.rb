s = gets.strip.split('').map(&:to_i)

result = s.length

(s.length-1).times do |i|
  next if s[i]==s[i+1]
  current=[i+1, s.length-i-1].max
  result = [result,current].min

end

p result
