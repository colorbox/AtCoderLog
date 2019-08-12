n=readline.strip.to_i
pp = readline.strip.split.map(&:to_i)

#p n
#p pp

ppp=pp.dup
result=0
r_result = 0
n.times do |i|
  reverse_i = n-1-i
  if ppp[reverse_i] == reverse_i+1
    r_result+=1
    ppp[reverse_i-1] = ppp[reverse_i] if reverse_i>0
  end

  if pp[i] == i+1
    result += 1
    pp[i+1] = pp[i] if i<n
  end
end

p [result, r_result].min
