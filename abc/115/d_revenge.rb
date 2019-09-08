n, x = gets.strip.split.map(&:to_i)

@burger = [1]
@meat = [1]

(1..n).each do |i|
  @burger[i] = @burger[i-1]*2+3
  @meat[i] = @meat[i-1]*2+1
end

def counter(l, x)
  return 0 if x.zero?
  return 1 if l.zero?

  if x >= @burger[l-1]+2
    return @meat[l-1]+1 + counter(l-1, x-(@burger[l-1]+2))
  else
    return counter(l-1, x-1)
  end
end

p counter(n, x)
