x=gets.strip.to_i

result = 0
sum=0
x.times do |num|
  sum+=(num+1)
  result+=1
  if sum >= x
    p result
    break
  end
end
