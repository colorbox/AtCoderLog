n, t = gets.strip.split.map(&:to_i)
a = gets.strip.split.map(&:to_i)

min = a.first
checker = []
a.each do |e|
  checker << e-min
  min = e if min > e
end

#p checker.group_by(&:itself)
#p checker.group_by(&:itself)[checker.max]
p checker.group_by(&:itself)[checker.max].length
