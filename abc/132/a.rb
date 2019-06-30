if readline.strip.split('').group_by{|c|c}.map{|x|x[1].count}==[2,2]
  puts 'Yes'
else
  puts 'No'
end
