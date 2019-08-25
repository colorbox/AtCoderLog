n = gets.strip.to_i
as = gets.strip.split.map(&:to_i)

cum_s = [0]
cum_x = [0]
n.times do |i|
  cum_s.push(cum_s[i] + as[i])
  cum_x.push(cum_x[i] ^ as[i])
end

#p as
#p cum_s
#p cum_x

result = 0
l=r=1

until r == n+1 do
#  p [l,r]
  if (cum_s[r]-cum_s[l-1] == cum_x[r]^cum_x[l-1])
    result += r-l+1
    r+=1
  else
    l+=1
  end
end

p result
