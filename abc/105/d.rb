n, m = gets.strip.split.map(&:to_i)
a = gets.strip.split.map {|e| e.to_i%m }

m_a = [a.first]
(1...n).each do |i|
  m_a[i] = (m_a[i-1]+a[i])%m
end

numbers = m_a.group_by(&:itself)

result=0
numbers.each do |_, arr|
  c = arr.length
  next if c<2

  result += c*(c-1)/2
#p result
end
result += m_a.count(&:zero?)


#p"--"
#p a
#p m_a
p result
