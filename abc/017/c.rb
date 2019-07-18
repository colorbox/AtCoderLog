n, m = gets.split.map(&:to_i)
lrs = readlines.map {|line| line.strip.split.map(&:to_i) }

points = [0]*(m+1)

n.times do |i|
  left = lrs[i][0]-1
  right = lrs[i][1]
  point = lrs[i].last
  points[left] += point
  points[right] -= point
end

point_dist = [points.first]

m.times do |index|
  point_dist[index+1] = point_dist[index] + points[index+1]
end

#p points
#p point_dist

sum = lrs.map(&:last).inject(:+)

result = 0

m.times do |index|
  result = [result, sum-point_dist[index]].max
end

p result
