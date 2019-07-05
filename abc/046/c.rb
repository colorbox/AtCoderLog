n=gets.strip.to_i

ta=readlines.map {|line| line.split(' ').map(&:to_i) }

coefficient = 1
(n-1).times do |index|
  before = ta[index]
  after = ta[index+1]
  # coefficient = [(before.first.to_f/after.first.to_f), (before.last.to_f/after.last.to_f)].max.ceil.to_i
  coefficient = [((before.first + after.first - 1)/after.first), ((before.last+after.last-1)/after.last)].max

  ta[index+1] = [after.first*coefficient, after.last*coefficient]
end

result = ta.last.inject(:+)

p result
