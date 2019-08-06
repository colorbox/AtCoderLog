e = gets.strip.split.map(&:to_i)
b = gets.strip.to_i
l = gets.strip.split.map(&:to_i)

count = e.length - (e-l).length

result = 8-count
result=1 if result==2
result =2 if result==3 && (l-e)==[b]
result=0 if result>5

puts result
