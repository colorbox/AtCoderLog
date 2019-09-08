n=gets.strip.to_i
h=gets.strip.split.map(&:to_i)

result = 0
current = h.first
tmp_result = 0
(1...n).each do |i|
  next_height = h[i]
  if next_height <= current
    tmp_result+=1
  else
    result = tmp_result if tmp_result > result
    tmp_result=0
  end
  current = next_height
end
result = tmp_result if tmp_result > result

p result
