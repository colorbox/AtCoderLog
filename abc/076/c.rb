s = gets.strip.split('')
t = gets.strip.split('')

if t.length > s.length
  puts 'UNRESTORABLE'
  exit
end

target_indice = []
(s.length-t.length+1).times do |index|
  target_indice.push(index) if s.slice(index, t.length).zip(t).all? {|c_s, c_t| c_s==c_t || c_s=='?' }
end

if target_indice.empty?
  puts 'UNRESTORABLE'
  exit
end

result = target_indice.map {|i|
  tmp = s.dup
  tmp[i..i+t.length-1]=t
  tmp.map {|c| c=='?' ? 'a' : c }.join('')
}.sort.first
puts result
