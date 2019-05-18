lines = readlines.map(&:split)
max, left, right = lines[0].map(&:to_i).sort.reverse

left_diff = max-left
right_diff = max-right

result =
  if(left_diff%2==0 && right_diff%2==0)
    (left_diff + right_diff)/2
  elsif(left_diff%2==1 && right_diff%2==1)
    (left_diff + right_diff - 1)/2 + 1
  elsif(left_diff%2==1 || right_diff%2==1)
    (left_diff + right_diff + 1)/2 + 1
  end
#puts [max,left,right,left_diff,right_diff]
puts result
