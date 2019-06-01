lines = readlines.map(&:strip)

n = lines[0].to_i
red_points = lines[1..n].map{|e|e.split.map(&:to_i)}
blue_points = lines[n+1..n*2].map{|e|e.split.map(&:to_i)}

red_points.sort!
blue_points.sort!

#p red_points
#p blue_points
#p '---'

result=0
blue_points.each do|blue|
  candidate_red_points = red_points.dup.keep_if {|red| red[0] < blue[0] && red[1] < blue[1] }
  sorted_candidates = candidate_red_points.sort_by {|r| r[1] }
#  sorted_candidates = candidate_red_points.sort
  red_point = sorted_candidates.last
#  p '='
#  p blue
#  p red_point
#  p red_points
  next if red_point.nil?
  red_points.delete(red_point)
  result+=1
end

p result


