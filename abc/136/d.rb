s = gets.strip.split('')

current = []
groups = []

s.each do |c|
  if current.last=='L' && c== 'R'
    groups.push(current)
    current = []
  end
  current.push(c)
end
groups.push(current)

result = []

groups.each do |group|

  r_count = group.select {|c| c=='R' }.length
  l_count = group.length - r_count
  l_value = r_value = group.length/2

  if group.length.odd?
    if l_count.odd?
      l_value+=1
    else
      r_value+=1
    end
  end

  (r_count-1).times { result.push(0) }
  result.push(r_value)
  result.push(l_value)
  (l_count-1).times { result.push(0) }

end

puts result.join(' ')
