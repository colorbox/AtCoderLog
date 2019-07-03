inputs = readlines.map {|line| line.strip.split.map(&:to_i) }

N, M = inputs.shift
ab = inputs

$n = N

def find_path(current, graphs, stops)
  current_stops = stops.dup
  current_stops.push(current).uniq!
  return 1 if current_stops.length == $n
  targets = graphs.select {|graph| graph.include?(current) }.flatten.uniq - current_stops

  targets.map {|target| find_path(target, graphs, current_stops + [target]) }.flatten
end

p find_path(1, ab, []).length
