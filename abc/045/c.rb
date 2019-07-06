s = gets.strip.split('')

result = 0

if s.length==1
  p s.first.to_i
  exit
end

(2**(s.length-1)).times do |index|

  current=s[0].to_i

  ("%0#{s.length-1}b" % index).split('').each_with_index do |chr, idx|
    if chr.to_i.zero?
      current = current*10 + s[idx+1].to_i
    else
      result += current
      current=s[idx+1].to_i
    end
  end
  result += current unless current.zero?

end

p result
