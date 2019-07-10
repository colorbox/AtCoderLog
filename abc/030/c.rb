n, m = gets.strip.split.map(&:to_i)
x, y = gets.strip.split.map(&:to_i)
a = gets.strip.split.map(&:to_i)
b = gets.strip.split.map(&:to_i)

current = 0
result = 0
last_a = a.last
last_b = b.last

on_b = false

while true do

  while !on_b && !a.empty? do
    from_a = a.shift
    if current<=from_a
      current = from_a+x
      on_b = true
      break
    end
  end

  while on_b && !b.empty? do
    from_b = b.shift
    if current<=from_b
      current = from_b+y
      result += 1
      on_b = false
      break
    end
  end

  break if current > [last_a, last_b].max || a.empty? || b.empty?
end

p result
