n, k = gets.strip.split.map(&:to_i)
numbers = readlines.map {|line| line.strip.split.map(&:to_i) }.sort_by {|e| e.first }

#p [n,k]
#p numbers

count = 0
numbers.each {|number|
  count+=number.last
  if k <= count
    p number.first
    exit
  end
}

