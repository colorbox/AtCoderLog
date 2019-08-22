s=gets.strip.split('')

s_chars = {}
(s).each_with_index do |c, i|
  s_chars[c] ||= [] if s_chars[c].nil?
  s_chars[c] << i
end

valid_chars = s_chars.keys.select {|k| s_chars[k].length > 1 }

#p s
#p s_chars
#p valid_chars

valid_chars.each do |k|
  (s_chars[k].length-1).times do |i|
    if s_chars[k][i+1] - s_chars[k][i]<=2
      puts [s_chars[k][i]+1, s_chars[k][i+1]+1].join(' ')
      exit
    end
  end
end

puts '-1 -1'

