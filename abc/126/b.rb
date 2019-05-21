lines = readlines.map(&:strip)
S = lines[0].split('')

left = S[0..1].join.to_i
right = S[2..3].join.to_i

#0,1-12,13-99
left_m = (left >= 1) && (left <= 12)
right_m = (right >= 1) && (right <= 12)

result = nil
if(left_m && right_m)
  result = 'AMBIGUOUS'
elsif(left_m && !right_m)
  result = 'MMYY'
elsif(!left_m && right_m)
  result = 'YYMM'
elsif(!left_m && !right_m)
  result = 'NA'
end

puts result

