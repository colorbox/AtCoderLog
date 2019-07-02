def find_common(left, right)
  result = ''
  grouped_left = left.split('').group_by{|x|x}
  grouped_right = right.split('').group_by{|x|x}
  ('a'..'z').to_a.each do |chr|
    l = grouped_left[chr]
    l_count = l ? l.size : 0
    r = grouped_right[chr]
    r_count = r ? r.size : 0
    result += chr*[l_count, r_count].min
  end
  result
end

n = gets.strip.to_i
s = readlines.map {|line| line.strip }

result = s.reduce {|sum, str|
  find_common(sum, str)
}

puts result.split('').sort.join('')
