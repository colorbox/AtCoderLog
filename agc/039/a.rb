s = gets.strip.split('')
k = gets.strip.to_i


if s.uniq.length==1
  p (s.length*k)/2; exit
end

f = (s.first==s.last)

rl = []
t=[s.shift]
s.each do |e|
  if e != t.last
    rl << t.length
    t=[e]
  else
    t<<e
  end
end
rl << t.length

result=0
if f
  first = rl.first
  last = rl.last

  result += first/2 + last/2

  rl[0] = rl[0]+rl.pop
  result += k*rl.map {|e|e/2}.inject(:+)

  result -= rl[0]/2

  p result
else
  p result = k*rl.map {|e|e/2}.inject(:+)
end
