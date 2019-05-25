lines = readlines.map(&:strip).map{|line| line.split.map(&:to_i)}

n, m = lines.shift
gates = lines

gate = lines[0]
gates.each do |lower, upper|
  gate[0] = lower if gate[0] < lower
  gate[1] = upper if gate[1] > upper
end

# puts gate.inspect

puts ((gate[0]..gate[1]).to_a & (1..n).to_a).count
