s = gets.strip.split('')

result = 0

current = s.shift
while(!s.empty?)
  target=s.shift
  result+=1 if(current!=target)
  current = target
end

p result

