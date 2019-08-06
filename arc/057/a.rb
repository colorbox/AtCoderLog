a, k = gets.strip.split.map(&:to_i)

thr = 2*(10**12)

if k.zero?
  p thr-a
  exit
end

current = a
days = 0
until thr <= current do
  days+=1
  current += (current*k+1)
end

p days
