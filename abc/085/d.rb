n, h = gets.strip.split.map(&:to_i)
a = readlines.map {|line| line.strip.split.map(&:to_i) }.sort

all_a = a.map(&:first).sort
all_b = a.map(&:last).sort

usual = all_a.last

result = 0

all_b.select {|e| e>=usual }.sort.reverse.each do |thr|
  h -= thr
  result += 1

  if h<=0
    p result
    exit
  end
end

result += 1 if h%usual > 0

result += (h/usual)

p result
