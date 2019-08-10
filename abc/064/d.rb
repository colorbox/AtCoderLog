n = gets.strip.to_i
s = gets.strip.split('')

stack = []

s.each do |c|
  if stack.last == ?( && c== ?)
    stack.pop
    next
  end
  stack.push(c)
end

open_braces, close_braces = stack.partition {|c| c==?( }

result = []
result += [?(] * close_braces.length
result += s
result += [?)] * open_braces.length

puts result.join('')
