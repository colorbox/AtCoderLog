n = gets.strip.to_i

result = []

if n.zero?
  p 0
  exit
end

if n.odd?
  result.push 1
  n -= 1
else
  result.push 0
end

until n==1 || n==-1
  n = -1 * (n / 2)
  if n.odd?
    result.push(1)
  else
    result.push(0)
  end
#  p [n, result]
end

result.push(1) if n==-1

puts result.reverse.join('')
