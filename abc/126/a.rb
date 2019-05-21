lines = readlines.map(&:strip)
n, k = lines[0].split.map(&:to_i)
s = lines[1].split('')

s[k-1] = 'a' if s[k-1]=='A'
s[k-1] = 'b' if s[k-1]=='B'
s[k-1] = 'c' if s[k-1]=='C'

puts s.join
