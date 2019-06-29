N = readline.to_i
A = readline.split.map(&:to_i)

count_4 = A.reject{|x|x%4!=0}
count_2 = (A-count_4).reject{|x|x%2!=0}
others_count = (A-count_4-count_2)

#p count_2
#p count_4
#p others_count

if( (count_2.size > 0 && (count_4.size>=others_count.size)) || (count_2.empty? && (count_4.size>=others_count.size-1)) )
  puts 'Yes'
else
  puts 'No'
end

