n, h  = gets.strip.split.map(&:to_i)
a, b, c, d, e = gets.strip.split.map(&:to_i)

if e > b*(n-1)+h
  p c*n
  exit
end

# at least one time lamadan

result = Float::INFINITY
n.times do |a_count|
  c_count = [0, (((n-a_count)*e - (b*a_count+h-1))/(d+e).to_f).ceil].max
  next if a_count + c_count > n || c_count < 0

  result = [result, a*a_count+c*c_count].min
#  p [a_count, c_count] if result==a*a_count+c*c_count
end

p result.to_i
