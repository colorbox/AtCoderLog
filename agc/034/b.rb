s = gets.chomp

def count(str)
  a, d, count= 0, 0, 0
  str.chars.each do |chr|
    a+=1 if chr=='A'
    count+=a if chr=='D'
  end
  count
end

s = s.gsub('BC', 'D')

s = s.chars.map{|e|
  if e=='A' || e=='D'
    e
  else
    '|'
  end
}.join.split('|').reject{|e|e==''}

s = s.map{|a|count(a)}

s=[0] if s.empty?
s=s.inject(:+)

puts s
