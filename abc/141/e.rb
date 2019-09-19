n = gets.strip.to_i
s=gets.strip

result = 0
t = ''
until s.empty?
  t += s.slice!(0)
  if s[t].nil?
    t.slice!(0)
  else
    len = t.length
    result = len if result < len
  end
end

p result
