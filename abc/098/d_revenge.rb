n = gets.strip.to_i
as = gets.strip.split.map(&:to_i)

l = r = 0
xor = sum = as[0]
result=0

while r<n

  if xor==sum
    result += (r-l+1)
    break if r==n-1
    r += 1
    xor = xor^as[r]
    sum += as[r]
  else
    xor = xor^as[l]
    sum -= as[l]
    l += 1
  end
end

p result
