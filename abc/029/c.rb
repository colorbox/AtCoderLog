n=gets.strip.to_i

(3**n).times do |index|
  pate = '0'*n
  number = (pate + index.to_s(3))[-1*n..-1]
  current = number.split('').map{|c|
    if c.to_i==0
      'a'
    elsif c.to_i==1
      'b'
    elsif c.to_i==2
      'c'
    end
  }.join('')
  puts current
end
